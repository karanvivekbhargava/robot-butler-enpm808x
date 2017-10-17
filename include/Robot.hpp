/** 
 *  @file    Robot.hpp
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

#ifndef ROBOT_HPP_
#define ROBOT_HPP_

#include <iostream>
#include <vector>
#include <string>
#include "CameraModule.hpp"
#include "PathPlanningModule.hpp"
#include "LidarModule.hpp"
#include "SensorFusionModule.hpp"

/**
 * @brief      Class for robot.
 */
class Robot {
 private:
  CameraModule camera_;
  LidarModule lidar_;
  SensorFusionModule fusion_;
  PathPlanningModule pathplanner_;

 public:
  /**
   * @brief      Default constructor
   */
  Robot();

  /**
   * @brief      Overloaded constructor
   *
   * @param[in]  str   The string
   */
  explicit Robot(std::string str);

  /**
   * @brief      Destroys the object.
   */
  ~Robot();

  /**
   * @brief      Starts the robots operation
   */
  float run();

  /**
   * @brief      Gets the diagnostic.
   *
   * @return     The diagnostic truth value.
   */
  bool getDiagnostic();
};

#endif  // ROBOT_HPP_
