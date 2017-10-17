/** 
 *  @file    Robot.cpp
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

#include <Robot.hpp>
#include <string>
#include <vector>

/**
 * @brief      Constructs the object.
 */
Robot::Robot() {
  // Set the inputs for the camera and the lidar
  // For the lidar data
  std::vector<std::vector<float>> input;
  for (int i = 0; i < 6; i++) {
    std::vector<float> p;
    if (i == 0) {
      p = {2, 1.2, 2};
    } else if (i == 1) {
      p = {1, 1, 3};
    } else {
      p = {10000, 10000, 1};
    }
    input.push_back(p);
  }
  lidar_.setInput(input);

  // Loads the camera image
  // Read the file
  cv::Mat image = cv::imread("../data/image_left.jpg", cv::IMREAD_COLOR);
  // Resize the image to 360x480, since its too large
  cv::Mat dst = cv::Mat::zeros(360, 480, image.type());
  cv::resize(image, dst, dst.size(), 0, 0, cv::INTER_AREA);
  camera_.setInput(dst);  // Sets the input to the resized image
  pathplanner_.setHeadingDirection(1);  // Set heading direction to 1
}

/**
 * @brief      Constructs the object.
 *
 * @param[in]  str   string from (left, center, right)
 */
Robot::Robot(std::string str) {
  // Set the lidar and camera inputs for all the cases
  if (str == "left") {
    // For the lidar data
    std::vector<std::vector<float>> input;
    for (int i = 0; i < 6; i++) {
      std::vector<float> p;
      if (i == 0) {
        p = {2, 1.2, 2};
      } else if (i == 1) {
        p = {1, 1, 3};
      } else {
        p = {10000, 10000, 1};
      }
      input.push_back(p);
    }
    lidar_.setInput(input);

    // Loads the camera image
    // Read the file
    cv::Mat image = cv::imread("../data/image_left.jpg", cv::IMREAD_COLOR);
    // Resize the image to 360x480, since its too large
    cv::Mat dst = cv::Mat::zeros(360, 480, image.type());
    cv::resize(image, dst, dst.size(), 0, 0, cv::INTER_AREA);
    camera_.setInput(dst);  // Sets the input to the resized image
  } else if (str == "center") {
    // For the lidar data
    std::vector<std::vector<float>> input;
    for (int i = 0; i < 6; i++) {
      std::vector<float> p;
      if (i == 0) {
        p = {3, 1.2, 2};
      } else if (i == 1) {
        p = {2.5, 1.2, 2};
      } else if (i == 2) {
        p = {2, 1.2, 2};
      } else if (i == 3) {
        p = {1, 1, 3};
      } else {
        p = {10000, 10000, 1};
      }
      input.push_back(p);
    }
    lidar_.setInput(input);

    // Loads the camera image
    // Read the file
    cv::Mat image = cv::imread("../data/image_center.jpg", cv::IMREAD_COLOR);
    // Resize the image to 360x480, since its too large
    cv::Mat dst = cv::Mat::zeros(360, 480, image.type());
    cv::resize(image, dst, dst.size(), 0, 0, cv::INTER_AREA);
    camera_.setInput(dst);  // Sets the input to the resized image
  } else if (str == "right") {
    // For the lidar data
    std::vector<std::vector<float>> input;
    for (int i = 0; i < 6; i++) {
      std::vector<float> p;
      if (i == 4) {
        p = {2, 1.2, 2};
      } else if (i == 5) {
        p = {1, 1, 3};
      } else {
        p = {10000, 10000, 1};
      }
      input.push_back(p);
    }
    lidar_.setInput(input);

    // Loads the camera image
    // Read the file
    cv::Mat image = cv::imread("../data/image_right.jpg", cv::IMREAD_COLOR);
    // Resize the image to 360x480, since its too large
    cv::Mat dst = cv::Mat::zeros(360, 480, image.type());
    cv::resize(image, dst, dst.size(), 0, 0, cv::INTER_AREA);
    camera_.setInput(dst);  // Sets the input to the resized image
  }

  pathplanner_.setHeadingDirection(1);  // Set heading direction to 1
}

/**
 * @brief      Destroys the object.
 */
Robot::~Robot() {}

/**
 * @brief      Starts the robots operation
 */
float Robot::run() {
  // Set probabilities for camera in the fusion object
  fusion_.setImageProbabilities(camera_.computeProbabilities());
  // Set probabilities for the lidar in the fusion object
  fusion_.setLidarProbabilities(lidar_.computeProbabilities());
  // Modify the heading direction using the fused probabilities
  pathplanner_.modifyHeadingDirection(fusion_.fuseData());
  // Print the heading direction
  int i = pathplanner_.getHeadingDirection();
  // Convert to degrees
  float delta = 20.0*(static_cast<float>(i) - 2.5);
  // Print statements
  std::cout << "Rotate robot ";
  if (delta < 0) {
    std::cout << "counter clockwise by " << delta << std::endl;
  } else if (delta > 0) {
    std::cout << "clockwise by " << delta << std::endl;
  }
  // Return the output
  return delta;
}

/**
 * @brief      Gets the diagnostic.
 *
 * @return     The diagnostic truth value.
 */
bool Robot::getDiagnostic() {
  // We will return this as true only when all the values are true
  return (camera_.getDiagnostic() &&
    lidar_.getDiagnostic() &&
    fusion_.getDiagnostic() &&
    pathplanner_.getDiagnostic());
}
