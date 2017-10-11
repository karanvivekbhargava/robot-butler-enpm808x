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

#include <PathPlanningModule.hpp>

/**
 * @brief      Constructs the object.
 */
PathPlanningModule::PathPlanningModule() {}

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
  // TODO(Karan): Set the direction
}

/**
 * @brief      Gets the diagnostic.
 *
 * @return     The diagnostic truth value.
 */
bool PathPlanningModule::getDiagnostic() {
  // TODO(Karan):
  return false;
}

/**
 * @brief      Gets the heading direction.
 *
 * @return     The heading direction.
 */
int PathPlanningModule::getHeadingDirection() {
  // TODO(Karan): get the heading direction
}

/**
 * @brief      Modify the heading direction
 *
 * @param[in]  probabilities  The probabilities
 */
void PathPlanningModule::modifyHeadingDirection(std::vector<float> probabilities) {
  // TODO(Karan): modify the heading direction using the probabilities
}