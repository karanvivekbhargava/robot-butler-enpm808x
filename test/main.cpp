/** 
 *  @file    main.cpp
 *  @author  Karan Vivek Bhargava
 *  @copyright MIT License
 *  
 *  @brief ENPM808X, Midsemester project
 *
 *  @section DESCRIPTION
 *  
 *  This program is testing the modules.
 *
 */

#include <gtest/gtest.h>

/**
 * @brief      This is the main function for testing
 *
 * @param[in]  argc  The argc
 * @param      argv  The argv
 *
 * @return     nothing, just runs all the tests
 */
int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
