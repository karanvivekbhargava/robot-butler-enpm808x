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

/**
 * @brief      Constructs the object.
 */
Robot::Robot() {
  pathplanner_.setHeadingDirection(1);  // Set heading direction to 1
}

/**
 * @brief      Destroys the object.
 */
Robot::~Robot() {}

/**
 * @brief      Starts the robots operation
 */
void Robot::run() {
  // Set probabilities for camera in the fusion object
  fusion_.setImageProbabilities(camera_.computeProbabilities());
  // Set probabilities for the lidar in the fusion object
  fusion_.setLidarProbabilities(lidar_.computeProbabilities());
  // Modify the heading direction using the fused probabilities
  pathplanner_.modifyHeadingDirection(fusion_.fuseData());
  // Print the heading direction
  int i = pathplanner_.getHeadingDirection();
  std::cout << "Modified path to " << i << std::endl;
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
