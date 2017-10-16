/** 
 *  @file    CameraModule.cpp
 *  @author  Karan Vivek Bhargava
 *  @copyright MIT License
 *  
 *  @brief ENPM808X, Midsemester project
 *
 *  @section DESCRIPTION
 *  
 *  This program is testing the camera module.
 *
 */

#include <gtest/gtest.h>
#include <memory>
#include <vector>
#include "CameraModule.hpp"

/**
 * @brief      Class for camera test.
 */
class CameraTest : public ::testing::Test {
 protected:
    CameraModule cam;  // Create an object to be used in the tests
};

/**
 * @brief      Test for Sanity, just checks whether
 * everything is in order.
 */
TEST_F(CameraTest, SanityCheck) {
  EXPECT_EQ(1, 1);
}

/**
 * @brief      Run diagnostics test
 *
 * @param[in]  CameraTest       cam object
 * @param[in]  DiagnosticsCheck Name of the test
 */
TEST_F(CameraTest, DiagnosticsCheck) {
  EXPECT_EQ(cam.getDiagnostic(), 1);
}

/**
 * @brief      Run probability test
 *
 * @param[in]  CameraTest                 cam object
 * @param[in]  ComputeProbabilitiesCheck  Name of the test
 */
TEST_F(CameraTest, ComputeProbabilitiesCheck) {
  // Initialize the probabilities
  std::vector<float> p = cam.computeProbabilities();
  std::vector<float> ref = {0, 0.700105, 0, 0, 0, 0};
  // Compare the values
  for (unsigned int i = 0; i < p.size(); i++) {
    EXPECT_NEAR(p[i], ref[i], 0.0001);
  }
}
