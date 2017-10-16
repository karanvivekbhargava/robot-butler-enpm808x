/** 
 *  @file    LidarTest.cpp
 *  @author  Karan Vivek Bhargava
 *  @copyright MIT License
 *  
 *  @brief ENPM808X, Midsemester project
 *
 *  @section DESCRIPTION
 *  
 *  This program is testing the lidar module.
 *
 */

#include <gtest/gtest.h>
#include <memory>
#include <vector>
#include "LidarModule.hpp"

/**
 * @brief      Class for lidar test.
 */
class LidarTest : public ::testing::Test {
 protected:
    LidarModule lidar;  // Create an object to be used in the tests
};

/**
 * @brief      Test for Sanity, just checks whether
 * everything is in order.
 */
TEST_F(LidarTest, SanityCheck) {
  EXPECT_EQ(1, 1);
}

/**
 * @brief      Run diagnostics test
 *
 * @param[in]  LidarTest        lidar object
 * @param[in]  DiagnosticsCheck Name of the test
 */
TEST_F(LidarTest, DiagnosticsCheck) {
  // Check whether diagnostics is true
  EXPECT_EQ(lidar.getDiagnostic(), 1);
}

/**
 * @brief      Run probability test
 *
 * @param[in]  LidarTest                  lidar object
 * @param[in]  ComputeProbabilitiesCheck  Name of the test
 */
TEST_F(LidarTest, ComputeProbabilitiesCheck) {
  // Initialize the probabilites
  std::vector<float> p = lidar.computeProbabilities();
  std::vector<float> ref = {0.761854, 0.904837, 0, 0, 0, 0};
  // Compare the values
  for (unsigned int i = 0; i < p.size(); i++) {
    EXPECT_NEAR(p[i], ref[i], 0.0001);
  }
}
