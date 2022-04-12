cmake_minimum_required(VERSION 3.14)
project(Prog)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(googletest)
include_directories(googletest/include googletest .)

add_executable(runTest test.cpp pathname.cpp pathname.h Terminal.h Terminal.cpp prglib.h)

target_link_libraries(runTest gtest gtest_main util)
