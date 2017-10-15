/** 
 *  @file    PathPlanningTest.cpp
 *  @author  Karan Vivek Bhargava
 *  @copyright MIT License
 *  
 *  @brief ENPM808X, Midsemester project
 *
 *  @section DESCRIPTION
 *  
 *  This program is testing the path planning module.
 *
 */

#include <gtest/gtest.h>
#include <memory>
#include <vector>
#include "PathPlanningModule.hpp"

class PathPlanningTest : public ::testing::Test {
 protected:
    PathPlanningModule planner;  // Create an object to be used in the tests
};

/**
 * @brief      Test for Sanity, just checks whether
 * everything is in order.
 */
TEST_F(PathPlanningTest, SanityCheck) {
  EXPECT_EQ(1, 1);
}

/**
 * @brief      Run diagnostics test
 *
 * @param[in]  PathPlanningTest path planning object
 * @param[in]  DiagnosticsCheck Name of the test
 */
TEST_F(PathPlanningTest, DiagnosticsCheck) {
  EXPECT_EQ(planner.getDiagnostic(), 1);
}

/**
 * @brief      Test for whether the direction is set or not
 *
 * @param[in]  PathPlanningTest   path planning object
 * @param[in]  SetDirectionCheck  Name of the test
 */
TEST_F(PathPlanningTest, SetDirectionCheck) {
  planner.setHeadingDirection(2);
  EXPECT_EQ(planner.getHeadingDirection(), 2);
}

/**
 * @brief      Test for whether the direction is modified
 *
 * @param[in]  PathPlanningTest   path planning object
 * @param[in]  SetDirectionCheck  Name of the test
 */
TEST_F(PathPlanningTest, ModificationCheck) {
  std::vector<float> p = {0.1, 0.2, 0.3, 0.4, 0.01, 0.5};
  planner.modifyHeadingDirection(p);
  EXPECT_EQ(planner.getHeadingDirection(), 4);
}
