/** 
 *  @file    SensorFusionModule.cpp
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
#include "SensorFusionModule.hpp"

/**
 * @brief      Constructs the object.
 */
SensorFusionModule::SensorFusionModule() {
  diagnostic_ = true;  // Set the diagnostics to true
}

/**
 * @brief      Destroys the object.
 */
SensorFusionModule::~SensorFusionModule() {}

/**
 * @brief      Sets the heading direction.
 *
 * @param[in]  input  The input
 */
void SensorFusionModule::setLidarProbabilities(std::vector<float> input) {
  lidarProbabilities_ = input;  // Set the input
}

/**
 * @brief      Sets the image probabilities.
 *
 * @param[in]  input  The input
 */
void SensorFusionModule::setImageProbabilities(std::vector<float> input) {
  imageProbabilities_ = input;  // Set the input
}

/**
 * @brief      Fuse the two sensor data
 *
 * @return     Fused sensor probabilities
 */
std::vector<float> SensorFusionModule::fuseData() {
  // Choose higher of both the probabilities and return a fused probability
  std::vector<float> fuse;
  for (unsigned int i = 0; i < imageProbabilities_.size(); i++) {
    if (imageProbabilities_[i] > lidarProbabilities_[i]) {
      fuse.push_back(imageProbabilities_[i]);
    } else {
      fuse.push_back(lidarProbabilities_[i]);
    }
  }
  return fuse;
}

/**
 * @brief      Gets the diagnostic.
 *
 * @return     The diagnostic truth value.
 */
bool SensorFusionModule::getDiagnostic() {
  return diagnostic_;  // return the diagnostics
}
