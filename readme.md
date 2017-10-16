<h1 align=center> ENPM808X - Robot Butler </h1>
<p align="center">
<a href="https://travis-ci.org/karanvivekbhargava/robot-butler-enpm808x">
<img src="https://travis-ci.org/karanvivekbhargava/robot-butler-enpm808x.svg?branch=master">
</a>
<a href='https://coveralls.io/github/karanvivekbhargava/robot-butler-enpm808x?branch=master'><img src='https://coveralls.io/repos/github/karanvivekbhargava/robot-butler-enpm808x/badge.svg?branch=master'/></a>
<a href='https://opensource.org/licenses/MIT'><img src='https://img.shields.io/badge/License-MIT-yellow.svg'/></a>
</p>

---
<p align="center">
<img src="https://cdn.andnowuknow.com/mainStoryImage/robot_butler_aug_2014_banner.jpg">
</p>

## Robot Overview

The Butler product by Acme Robotics is one of its flagship products. It performs best for an environment where things are to be transported to and fro from one area to another. Equipped with a 16MP camera and the best of class custom lidar sensor, its our best offering. The butler has intelligent algorithms running under its hood which allow it to percieve its environment by using these sensors. This allows the butler to avoid hitting obstacles and helps it serve you better.

## New Feature List
We tirelessly work on our robots so that you don't have to. Our new offerings in software are included below.
* Estimation of object distances using camera data: While other companies are defining state of the art algorithms on the road, we do it in your workplace. Making our robots 30% less likely to crash into objects than our competitors.
* Using lidar to map your environment: The butler records its surroundings in 3D so that it can see obstacles before they hit it.
* Advanced data fusion algorithms: Our robots are cool but don't be fooled by their innocent appearance, they work super hard on the inside to crunch numbers faster than ever.
* Path Planning: Using our custom sensors and the fusion technique, we can better plan the paths to avoid obstacles

## The Camera
The butler has a 16MP front facing camera. Its camera module consists of an FPGA which can perform custom algorithms at a mind boggling pace. Once the input image arrives, the module does a perspective transform on it. This gives us a birds eye view which is then passed to a thresholder. The binarized image from the thresholder is then used to calculate the probabilities of hitting the nearby obstacles. We use a gaussian probability distribution to compute the same.

## The Lidar
The lidar gives a three dimensional point cloud representation of its surroundings. It uses this information and 'flattens' it out. This results in all the points being in some eucledean plane and the robot being the origin. It computes the distances from the obstacles and returns gaussian probabilitites to all the possible heading directions of the robot.

## Sensor Fusion
After the camera and lidar do the hard work of putting the information in a sensible format, the sensor fusion module takes the two readings and selects the higher probability of the two, for each heading direction. Although this might result in some noisy outputs, it gives a high probability of avoiding obstacles.

## Path Planning
The path planner uses the fused sensor output to determine what should be the next heading direction. This is done by selecting the heading direction which results in the least probability of hitting any obstacles.

## SIP Overview
Click this link to view the product backlog, time sheets, defect logs and release backlog - [link](https://docs.google.com/spreadsheets/d/1WOvV6iL4gGOF8Qacwj2R3Lom71wziKXEf_UEhdGfOuY/edit?usp=sharing)

Care has been taken to design the SIP tasks such that they have a direct relation to the previous tasks. This helps in better time estimation. For instance, the change in time taken for stub implementation is proportional to the change in time taken to implement the methods. This gave me a good idea to rethink about the allotment of time for future tasks.

## Overview

Simple starter C++ project with:

- cmake
- googletest

## Standard install via command-line
```
git clone --recursive https://github.com/karanvivekbhargava/robot-butler-enpm808x
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```

## Building for code coverage (for assignments beginning in Week 4)
```
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser.

## Working with Eclipse IDE ##

## Installation

In your Eclipse workspace directory (or create a new one), checkout the repo (and submodules)
```
mkdir -p ~/workspace
cd ~/workspace
git clone --recursive https://github.com/dpiet/cpp-boilerplate
```

In your work directory, use cmake to create an Eclipse project for an [out-of-source build] of cpp-boilerplate

```
cd ~/workspace
mkdir -p boilerplate-eclipse
cd boilerplate-eclipse
cmake -G "Eclipse CDT4 - Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug -D CMAKE_ECLIPSE_VERSION=4.7.0 -D CMAKE_CXX_COMPILER_ARG1=-std=c++14 ../cpp-boilerplate/
```

## Import

Open Eclipse, go to File -> Import -> General -> Existing Projects into Workspace -> 
Select "boilerplate-eclipse" directory created previously as root directory -> Finish

# Edit

Source files may be edited under the "[Source Directory]" label in the Project Explorer.


## Build

To build the project, in Eclipse, unfold boilerplate-eclipse project in Project Explorer,
unfold Build Targets, double click on "all" to build all projects.

## Run

1. In Eclipse, right click on the boilerplate-eclipse in Project Explorer,
select Run As -> Local C/C++ Application

2. Choose the binaries to run (e.g. shell-app, cpp-test for unit testing)


## Debug


1. Set breakpoint in source file (i.e. double click in the left margin on the line you want 
the program to break).

2. In Eclipse, right click on the boilerplate-eclipse in Project Explorer, select Debug As -> 
Local C/C++ Application, choose the binaries to run (e.g. shell-app).

3. If prompt to "Confirm Perspective Switch", select yes.

4. Program will break at the breakpoint you set.

5. Press Step Into (F5), Step Over (F6), Step Return (F7) to step/debug your program.

6. Right click on the variable in editor to add watch expression to watch the variable in 
debugger window.

7. Press Terminate icon to terminate debugging and press C/C++ icon to switch back to C/C++ 
perspetive view (or Windows->Perspective->Open Perspective->C/C++).


## Plugins

- CppChEclipse

    To install and run cppcheck in Eclipse

    1. In Eclipse, go to Window -> Preferences -> C/C++ -> cppcheclipse.
    Set cppcheck binary path to "/usr/bin/cppcheck".

    2. To run CPPCheck on a project, right click on the project name in the Project Explorer 
    and choose cppcheck -> Run cppcheck.


- Google C++ Sytle

    To include and use Google C++ Style formatter in Eclipse

    1. In Eclipse, go to Window -> Preferences -> C/C++ -> Code Style -> Formatter. 
    Import [eclipse-cpp-google-style][reference-id-for-eclipse-cpp-google-style] and apply.

    2. To use Google C++ style formatter, right click on the source code or folder in 
    Project Explorer and choose Source -> Format

[reference-id-for-eclipse-cpp-google-style]: https://raw.githubusercontent.com/google/styleguide/gh-pages/eclipse-cpp-google-style.xml

- Git

    It is possible to manage version control through Eclipse and the git plugin, but it typically requires creating another project. If you're interested in this, try it out yourself and contact me on Canvas.
