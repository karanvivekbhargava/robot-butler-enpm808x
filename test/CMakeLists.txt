set(GTEST_SHUFFLE 1)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

add_executable(
    cpp-test
    main.cpp
    CameraTest.cpp
    LidarTest.cpp
    PathPlanningTest.cpp
    SensorFusionTest.cpp
    ../app/CameraModule.cpp
    ../app/LidarModule.cpp
    ../app/PathPlanningModule.cpp
    ../app/SensorFusionModule.cpp
    
)

target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include 
                                           ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(cpp-test PUBLIC gtest ${OpenCV_LIBS})
