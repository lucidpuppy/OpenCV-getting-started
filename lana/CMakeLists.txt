cmake_minimum_required (VERSION 2.6)
cmake_policy(SET CMP0012 NEW)
PROJECT(lana)

#requires OpenCV
FIND_PACKAGE(OpenCV 3.0.0 REQUIRED)

MESSAGE("OpenCV Version : ${OpenCV_VERSION}")
MESSAGE("OpenCV Inc dirs : ${OpenCV_INCLUDE_DIRS}")
MESSAGE("OpenCV Libs dirs : ${OpenCV_LIB_DIR}")

include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OPENCV_LIB_DIR})
ADD_EXECUTABLE(${PROJECT_NAME} lana.cpp)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ,  ${OpenCV_LIBS})
