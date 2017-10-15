/** 
 *  @file    main.cpp
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

#include <Robot.hpp>

/**
 * @brief      main function
 *
 * @return     nothing
 */
int main() {
  Robot wallE;  // Initialize the robot
  if (wallE.getDiagnostic()) {  // Run robot only if the diagnostic is true
    std::cout << "Diagnostics are fine." << std::endl;
    wallE.run();  // Run the robot
  } else {  // Point to an error if diagnostic fails
    std::cout << "[ERROR] problem in diagnostics" << std::endl;
  }
  return 0;
}
