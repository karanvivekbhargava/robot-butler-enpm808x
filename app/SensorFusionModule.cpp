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

#include <SensorFusionModule.hpp>

/**
 * @brief      Constructs the object.
 */
SensorFusionModule::SensorFusionModule() {}

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
  // TODO(Karan): Set the input
}

/**
 * @brief      Sets the image probabilities.
 *
 * @param[in]  input  The input
 */
void SensorFusionModule::setImageProbabilities(std::vector<float> input) {
  // TODO(Karan): Set the input
}

/**
 * @brief      Fuse the two sensor data
 *
 * @return     Fused sensor probabilities
 */
std::vector<float> SensorFusionModule::fuseData() {
  // TODO(Karan): Set the input
}

/**
 * @brief      Gets the diagnostic.
 *
 * @return     The diagnostic truth value.
 */
bool SensorFusionModule::getDiagnostic() {
  // TODO(Karan):
  return false;
}