/** 
 *  @file    SensorFusionModule.hpp
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

#ifndef SENSORFUSIONMODULE_HPP_
#define SENSORFUSIONMODULE_HPP_

#include <iostream>
#include <vector>

/**
 * @brief      Class for sensor fusion module.
 */
class SensorFusionModule {
 private:
  std::vector<float> imageProbabilities_, lidarProbabilities_;
  bool diagnostic_;

 public:
  /**
   * @brief      Constructor
   */
  SensorFusionModule();

  /**
   * @brief      Destroys the object.
   */
  ~SensorFusionModule();

  /**
   * @brief      Sets the lidar probabilities.
   *
   * @param[in]  input  The input
   */
  void setLidarProbabilities(std::vector<float> input);

  /**
   * @brief      Sets the image probabilities.
   *
   * @param[in]  input  The input
   */
  void setImageProbabilities(std::vector<float> input);

  /**
   * @brief      Fuse the two sensor data
   *
   * @return     Fused sensor probabilities
   */
  std::vector<float> fuseData();

  /**
   * @brief      Gets the diagnostic.
   *
   * @return     The diagnostic truth value.
   */
  bool getDiagnostic();
};

#endif  // SENSORFUSIONMODULE_HPP_
