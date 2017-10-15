/** 
 *  @file    PathPlanningModule.hpp
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

#ifndef PATHPLANNINGMODULE_HPP_
#define PATHPLANNINGMODULE_HPP_

#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @brief      Class for path planning module.
 */
class PathPlanningModule {
 private:
  int currentHeadingDirection_ = 0;
  bool diagnostic_ = false;

 public:
  /**
   * @brief      Constructor
   */
  PathPlanningModule();

  /**
   * @brief      Destroys the object.
   */
  ~PathPlanningModule();

  /**
   * @brief      Sets the heading direction.
   *
   * @param[in]  input  The input
   */
  void setHeadingDirection(int input);

  /**
   * @brief      Gets the diagnostic.
   *
   * @return     The diagnostic truth value.
   */
  bool getDiagnostic();

  /**
   * @brief      Gets the heading direction.
   *
   * @return     The heading direction.
   */
  int getHeadingDirection();

  /**
   * @brief      Modify the heading direction
   *
   * @param[in]  probabilities  The probabilities
   */
  void modifyHeadingDirection(std::vector<float> probabilities);
};

#endif  // PATHPLANNINGMODULE_HPP_
