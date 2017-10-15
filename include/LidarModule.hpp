/** 
 *  @file    LidarModule.hpp
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

#ifndef LIDARMODULE_HPP_
#define LIDARMODULE_HPP_

#include <math.h>
#include <iostream>
#include <vector>
#include <string>

/**
 * @brief      Class for lidar module.
 */
class LidarModule {
 private:
  bool diagnostic_ = false;
  std::vector<std::vector<float>> inputPts_, flattenedPts_;

 public:
  /**
   * @brief      Constructor
   */
  LidarModule();

  /**
   * @brief      Destroys the object.
   */
  ~LidarModule();

  /**
   * @brief      Sets the input.
   *
   * @param[in]  input  The input
   */
  void setInput(std::vector<std::vector<float>> input);

  /**
   * @brief      Gets the diagnostic.
   *
   * @return     The diagnostic truth value.
   */
  bool getDiagnostic();

  /**
   * @brief      Project the points onto the ground
   */
  void flatten();

  /**
   * @brief      Calculates the probabilities.
   *
   * @return     The probabilities for heading directions.
   */
  std::vector<float> computeProbabilities();
};

#endif  // LIDARMODULE_HPP_
