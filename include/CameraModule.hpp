/** 
 *  @file    CameraModule.hpp
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

#ifndef CAMERAMODULE_HPP_
#define CAMERAMODULE_HPP_

#include <opencv2/opencv.hpp>
#include <math.h>
#include <iostream>
#include <vector>

#define PI 3.14159265

/**
 * @brief      Class for camera module.
 */
class CameraModule {
 private:
  cv::Mat inputImage_, intermediateImage_, warpedImage_;
  bool diagnostic_ = false;
  std::vector<float> outputValues_;

 public:
  /**
   * @brief      Constructor
   */
  CameraModule();

  /**
   * @brief      Destroys the object.
   */
  ~CameraModule();

  /**
   * @brief      Sets the input image.
   *
   * @param[in]  input  The input image
   */
  void setInput(cv::Mat input);

  /**
   * @brief      Gets the diagnostic.
   *
   * @return     The diagnostic truth value.
   */
  bool getDiagnostic();

  /**
   * @brief      Warps the image and binarizes it
   */
  void warpAndBinarize();

  /**
   * @brief      Calculates the probabilities.
   *
   * @return     The probabilities for heading directions.
   */
  std::vector<float> computeProbabilities();
};

#endif  // CAMERAMODULE_HPP_
