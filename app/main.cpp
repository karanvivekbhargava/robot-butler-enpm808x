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
#include <string>

/**
 * @brief      main function
 *
 * @return     nothing
 */
int main(int argc, char* argv[]) {
  if (argc == 2) {
    std::string str(argv[1]);
    if ((str == "left") ||
      (str == "center") ||
      (str == "right")) {
      Robot wallE(str);  // Initialize the robot
      if (wallE.getDiagnostic()) {  // Run robot only if the diagnostic is true
        std::cout << "[OK] Diagnostics are fine." << std::endl;
        wallE.run();  // Run the robot
      } else {  // Point to an error if diagnostic fails
        std::cout << "[ERROR] problem in diagnostics" << std::endl;
      }
      return 0;
    } else {
      std::cout << "Invalid input: choose one of left, center or right"
        << std::endl;
      return -1;
    }
  } else if (argc == 1) {
    Robot wallE;  // Initialize the robot
    if (wallE.getDiagnostic()) {  // Run robot only if the diagnostic is true
      std::cout << "[OK] Diagnostics are fine." << std::endl;
      wallE.run();  // Run the robot
    } else {  // Point to an error if diagnostic fails
      std::cout << "[ERROR] problem in diagnostics" << std::endl;
    }
    return 0;
  } else {
    std::cout << "Invalid number of arguments" << std::endl;
    return -1;
  }
}
