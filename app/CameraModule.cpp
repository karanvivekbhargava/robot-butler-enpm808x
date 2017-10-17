/** 
 *  @file    CameraModule.cpp
 *  @author  Karan Vivek Bhargava
 *  @copyright MIT License
 *  
 *  @brief ENPM808X, Midsemester project
 *
 *  @section DESCRIPTION
 *  
 *  This program is controlling a robot's heading direction
 *  using sensor fusion.
 *
 */

#include <vector>
#include "CameraModule.hpp"

/**
 * @brief      Constructs the object.
 */
CameraModule::CameraModule() {
  diagnostic_ = true;  // Default to true value
  // Loads the camera image
  // Read the file
  cv::Mat image = cv::imread("../data/image_left.jpg", cv::IMREAD_COLOR);
  // Resize the image to 360x480, since its too large
  cv::Mat dst = cv::Mat::zeros(360, 480, image.type());
  cv::resize(image, dst, dst.size(), 0, 0, cv::INTER_AREA);
  setInput(dst);  // Sets the input to the resized image
}

/**
 * @brief      Destroys the object.
 */
CameraModule::~CameraModule() {}

/**
 * @brief      Sets the input image.
 *
 * @param[in]  input  The input image
 */
void CameraModule::setInput(cv::Mat input) {
  inputImage_ = input;  // Set the image as the input
}

/**
 * @brief      Gets the diagnostic.
 *
 * @return     The diagnostic truth value.
 */
bool CameraModule::getDiagnostic() {
  return diagnostic_;  // Return the diagnostics
}

/**
 * @brief      Warps the image and binarizes it
 */
void CameraModule::warpAndBinarize() {
  // Change of variable for clarity
  cv::Mat src = inputImage_;
  cv::Mat warp_dst = cv::Mat::zeros(src.rows*2, src.cols*2, src.type());

  // Placeholders for the points used in the transformation
  cv::Point2f srcTri[4];
  cv::Point2f dstTri[4];

  // Set 4 points to calculate the  Affine Transform
  srcTri[0] = cv::Point2f(src.cols/4, src.rows/2);
  srcTri[1] = cv::Point2f(0, src.rows - 1);
  srcTri[2] = cv::Point2f(src.cols-1, src.rows - 1);
  srcTri[3] = cv::Point2f(src.cols*3/4, src.rows/2);

  dstTri[0] = cv::Point2f(warp_dst.cols/2 - src.cols/2,
    warp_dst.rows-src.rows-1);
  dstTri[1] = cv::Point2f(warp_dst.cols/2 - src.cols/2,
    warp_dst.rows-1);
  dstTri[2] = cv::Point2f(warp_dst.cols/2 + src.cols/2,
    warp_dst.rows-1);
  dstTri[3] = cv::Point2f(warp_dst.cols/2 + src.cols/2,
    warp_dst.rows-src.rows-1);

  // Get the Affine Transform
  cv::Mat warp_mat = getPerspectiveTransform(srcTri, dstTri);

  // Apply the Affine Transform just found to the src image
  cv::warpPerspective(src, warp_dst, warp_mat, warp_dst.size());

  // Apply thresholding
  cv::inRange(warp_dst, cv::Scalar(1, 1, 1),
    cv::Scalar(150, 60, 150),
    intermediateImage_);

  // Erode the image
  int erosion_elem = 0;
  int erosion_size = 1;
  int erosion_type = 0;
  if (erosion_elem == 0) { erosion_type = cv::MORPH_RECT; }
  cv::Mat element = cv::getStructuringElement(erosion_type,
    cv::Size(2*erosion_size + 1, 2*erosion_size+1),
    cv::Point(erosion_size, erosion_size) );
  cv::erode(intermediateImage_,
    intermediateImage_,
    element,
    cv::Point(-1, -1),
    5);

  // Store the angles to check for obstacles
  int degree = 120;
  int n = 6;
  float increment = static_cast<float>(degree)/static_cast<float>(n-1);
  float start_angle = 90.0 - degree/2.0;
  std::vector<float> angles;

  for (int i = 0 ; i < n ; i++) {
    angles.push_back(start_angle + static_cast<float>(i)*increment);
  }

  // Set the (x0, y0), This is the point the camera is at
  float x0 = intermediateImage_.cols/2;
  float y0 = intermediateImage_.rows-1;

  // Iterate over the lines to find eucledean distances
  std::vector<float> dist;
  // Use normal iterator since we are iterating over pixel location
  for (int i = 0 ; i < n ; i++) {
    float xend = 0, yend = 0;
    // Find intersection between the lines of the image frame
    float m = tan(angles[i]*PI/180.0);
    // Handle very low values of the slope
    if (abs(m) < 0.0001) {
      if (m <= 0) {
        m = -0.0001;
      } else {
        m = 0.0001;
      }
    }
    float c = y0 - m*x0;
    // Left side of image frame
    float y_l = c;
    // Right side of image frame
    float y_r = m*(intermediateImage_.cols-1) + c;
    // Top side of image frame
    float x_t = -c/m;
    // Check validity of the intersection points
    if ((y_l >= 0) && (y_l <= static_cast<float>(intermediateImage_.rows-1))) {
      yend = floor(y_l);
      xend = 0;
    } else if ((y_r >= 0) &&
      (y_r <= static_cast<float>(intermediateImage_.rows-1))) {
      yend = floor(y_r);
      xend = floor(intermediateImage_.cols-1);
    } else {
      yend = 0;
      xend = floor(x_t);
    }
    // Check for point which is closest to obstacle on the line
    for (int j = y0 ; j > yend ; j--) {
      int x = floor((static_cast<float>(j) - c)/m);
      if ((x >= 0) && x < intermediateImage_.cols) {
        if (intermediateImage_.at<uchar>(j, x) == 255) {
          xend = x;
          yend = j;
          break;
        }
      }
    }

    // Calculate the eucledian distances
    float d = sqrt(pow((xend-x0), 2) + pow((yend-y0), 2));
    if (d > intermediateImage_.rows/2) {
      d = 10000;
    }
    dist.push_back(d);
  }

  // Calculate probabilities from the distances
  float var = 100000;
  float mean = 0;
  for (auto i : dist) {
    float p =  exp(-pow((i-mean), 2.0)/(2.0*var));  // Simple Gaussian
    outputValues_.push_back(p);
  }
}

/**
 * @brief      Calculates the probabilities.
 *
 * @return     The probabilities for heading directions.
 */
std::vector<float> CameraModule::computeProbabilities() {
  warpAndBinarize();  // Warp and binarize to get the probabilities
  return outputValues_;  // return the probabilities
}
