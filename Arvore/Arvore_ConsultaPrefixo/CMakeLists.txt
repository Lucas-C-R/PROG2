cmake_minimum_required(VERSION 3.14)
project(Prog)

set(CMAKE_CXX_STANDARD 14)

add_executable(Prog main.cpp libs/BasicTree.cpp)
include_directories(.)
add_subdirectory(googletest)
include_directories(googletest/include googletest)

add_executable(runTerm termtest.cpp Terminal.cpp Terminal.h libs/BasicTree.cpp)

target_link_libraries(runTerm gtest gtest_main util)

#target_link_libraries(Prog -L${CMAKE_SOURCE_DIR}/libs prglib util)
