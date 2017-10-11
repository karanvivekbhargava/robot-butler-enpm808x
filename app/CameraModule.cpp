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

#include <CameraModule.hpp>

/**
 * @brief      Constructs the object.
 */
CameraModule::CameraModule() {}

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
  // TODO(Karan): Set the input image
}

/**
 * @brief      Gets the diagnostic.
 *
 * @return     The diagnostic truth value.
 */
bool CameraModule::getDiagnostic() {
  // TODO(Karan):
  return false;
}

/**
 * @brief      Warps the image and binarizes it
 */
void CameraModule::warpAndBinarize() {
  // TODO(Karan): warp and binarize the image
}

/**
 * @brief      Calculates the probabilities.
 *
 * @return     The probabilities for heading directions.
 */
std::vector<float> CameraModule::computeProbabilities() {
  return outputValues_;
}