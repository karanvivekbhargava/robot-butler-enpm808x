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

#include <vector>
#include <string>
#include "LidarModule.hpp"

/**
 * @brief      Constructs the object.
 */
LidarModule::LidarModule() {
  diagnostic_ = true;
}

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
  inputPts_ = input;  // Set the input points
}

/**
 * @brief      Gets the diagnostic.
 *
 * @return     The diagnostic truth value.
 */
bool LidarModule::getDiagnostic() {
  return diagnostic_;
}

/**
 * @brief      Project the points onto the ground
 */
void LidarModule::flatten() {
  // Remove the third coordinate to project it onto the ground
  for (auto i : inputPts_) {
    std::vector<float> p;
    for (int j = 0; j < 2; j++) {
      p.push_back(i[j]);
    }
    flattenedPts_.push_back(p);
  }
}

/**
 * @brief      Calculates the probabilities.
 *
 * @return     The probabilities for heading directions.
 */
std::vector<float> LidarModule::computeProbabilities() {
  // Flatten the points
  flatten();

  // Calculate the eucledian distances
  std::vector<float> dist;
  for (auto i : flattenedPts_) {
    float d = sqrt(pow(i[0], 2) + pow(i[1], 2));
    if (d > 10000) {
      d = 10000;
    }
    dist.push_back(d);
  }

  // Calculate the probabilties
  std::vector<float> outputValues;
  float var = 10;
  float mean = 0;
  for (auto i : dist) {
    float p =  exp(-pow((i-mean), 2.0)/(2.0*var));  // Use a gaussian
    outputValues.push_back(p);
  }

  // Return the output probabilities
  return outputValues;
}
