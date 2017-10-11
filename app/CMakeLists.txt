add_executable(shell-app main.cpp Robot.cpp CameraModule.cpp LidarModule.cpp PathPlanningModule.cpp SensorFusionModule.cpp)

# Link the OpenCV_LIBS with binary
target_link_libraries( shell-app ${OpenCV_LIBS} )

include_directories(
    ${CMAKE_SOURCE_DIR}/include
)
