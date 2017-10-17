/** 
 *  @file    RobotTest.cpp
 *  @author  Karan Vivek Bhargava
 *  @copyright MIT License
 *  
 *  @brief ENPM808X, Midsemester project
 *
 *  @section DESCRIPTION
 *  
 *  This program is testing the robot module.
 *
 */

#include <gtest/gtest.h>
#include <memory>
#include <vector>
#include <string>
#include "Robot.hpp"

/**
 * @brief      Class for Robot test.
 */
class RobotTest : public ::testing::Test {
 protected:
    // Create objects to be used in the tests
    std::string left = "left";
    std::string right = "right";
    std::string center = "center";
    Robot rob;  //
    Robot robL = Robot(left);
    Robot robC = Robot(center);
    Robot robR = Robot(right);
};

/**
 * @brief      Test for Sanity, just checks whether
 * everything is in order.
 */
TEST_F(RobotTest, SanityCheck) {
  EXPECT_EQ(1, 1);
}

/**
 * @brief      Run diagnostics test
 *
 * @param[in]  RobotTest        Contains all the objects
 * @param[in]  DiagnosticsCheck Name of the test
 */
TEST_F(RobotTest, DiagnosticsCheck) {
  EXPECT_EQ(rob.getDiagnostic(), 1);
  EXPECT_EQ(robL.getDiagnostic(), 1);
  EXPECT_EQ(robC.getDiagnostic(), 1);
  EXPECT_EQ(robR.getDiagnostic(), 1);
}

/**
 * @brief      Test whether robot is running
 *
 * @param[in]  RobotTest       Contains all the objects
 * @param[in]  runCheck        Name of the test
 */
TEST_F(RobotTest, runCheck) {
  EXPECT_NEAR(rob.run(), -10.0, 0.01);
  EXPECT_NEAR(robL.run(), -10.0, 0.01);
  EXPECT_NEAR(robC.run(), 50.0, 0.01);
  EXPECT_NEAR(robR.run(), -50.0, 0.01);
}
