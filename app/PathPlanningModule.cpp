/** 
 *  @file    PathPlanningModule.cpp
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

#include <algorithm>
#include <vector>
#include "PathPlanningModule.hpp"

/**
 * @brief      Constructs the object.
 */
PathPlanningModule::PathPlanningModule() {
  diagnostic_ = true;  // Set the diagnostics value
}

/**
 * @brief      Destroys the object.
 */
PathPlanningModule::~PathPlanningModule() {}

/**
 * @brief      Sets the heading direction.
 *
 * @param[in]  input  The input
 */
void PathPlanningModule::setHeadingDirection(int input) {
  currentHeadingDirection_ = input;  // Set the direction
}

/**
 * @brief      Gets the diagnostic.
 *
 * @return     The diagnostic truth value.
 */
bool PathPlanningModule::getDiagnostic() {
  return diagnostic_;  // returns the direction
}

/**
 * @brief      Gets the heading direction.
 *
 * @return     The heading direction.
 */
int PathPlanningModule::getHeadingDirection() {
  return currentHeadingDirection_;  // returns the heading direction
}

/**
 * @brief      Modify the heading direction
 *
 * @param[in]  probabilities  The probabilities
 */
void PathPlanningModule::modifyHeadingDirection(
  std::vector<float> probabilities) {
  // Find the minimum probability
  auto i = std::min_element(probabilities.begin(), probabilities.end());
  // Get the index of the minimum probability
  auto itr = std::distance(probabilities.begin(), i);
  // Set the heading direction
  setHeadingDirection(itr);
}
