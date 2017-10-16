/** 
 *  @file    SensorFusion.cpp
 *  @author  Karan Vivek Bhargava
 *  @copyright MIT License
 *  
 *  @brief ENPM808X, Midsemester project
 *
 *  @section DESCRIPTION
 *  
 *  This program is testing the sensor fusion module.
 *
 */

#include <gtest/gtest.h>
#include <memory>
#include <vector>
#include "SensorFusionModule.hpp"

/**
 * @brief      Class for sensor fusion test.
 */
class SensorFusionTest : public ::testing::Test {
 protected:
    SensorFusionModule fusion;  // Create an object to be used in the tests
};

/**
 * @brief      Test for Sanity, just checks whether
 * everything is in order.
 */
TEST_F(SensorFusionTest, SanityCheck) {
  EXPECT_EQ(1, 1);  // Check whether 1=1?
}

/**
 * @brief      Run diagnostics test
 *
 * @param[in]  SensorFusionTest sensor fusion object
 * @param[in]  DiagnosticsCheck Name of the test
 */
TEST_F(SensorFusionTest, DiagnosticsCheck) {
  // Check whether the diagnostic is true
  EXPECT_EQ(fusion.getDiagnostic(), 1);
}

/**
 * @brief      Run fusion test
 *
 * @param[in]  SensorFusionTest           sensor fusion object
 * @param[in]  ComputeProbabilitiesCheck  Name of the test
 */
TEST_F(SensorFusionTest, FusionCheck) {
  // Initialize the probabilites
  std::vector<float> pimage = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6};
  std::vector<float> plidar = {0.6, 0.5, 0.4, 0.3, 0.2, 0.1};
  // Set the probabilities in the fusion module
  fusion.setLidarProbabilities(plidar);
  fusion.setImageProbabilities(pimage);
  // Get the fused probabilites
  std::vector<float> p = fusion.fuseData();
  std::vector<float> ref = {0.6, 0.5, 0.4, 0.4, 0.5, 0.6};
  // Compare with reference
  for (unsigned int i = 0; i < p.size(); i++) {
    EXPECT_NEAR(p[i], ref[i], 0.0001);
  }
}
