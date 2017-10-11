/** 
 *  @file    LidarModule.cpp
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

#include <LidarModule.hpp>

/**
 * @brief      Constructs the object.
 */
LidarModule::LidarModule() {}

/**
 * @brief      Destroys the object.
 */
LidarModule::~LidarModule() {}

/**
 * @brief      Sets the input image.
 *
 * @param[in]  input  The input image
 */
void LidarModule::setInput(std::vector<std::vector<float>> input) {
  // TODO(Karan): Set the input
}

/**
 * @brief      Gets the diagnostic.
 *
 * @return     The diagnostic truth value.
 */
bool LidarModule::getDiagnostic() {
  // TODO(Karan):
  return false;
}

/**
 * @brief      Project the points onto the ground
 */
void LidarModule::flatten() {
  // TODO(Karan): flatten the points
}

/**
 * @brief      Calculates the probabilities.
 *
 * @return     The probabilities for heading directions.
 */
std::vector<float> LidarModule::computeProbabilities() {
  // TODO(Karan): calculate the probabilities
  std::vector<float> outputValues;
  return outputValues;
}