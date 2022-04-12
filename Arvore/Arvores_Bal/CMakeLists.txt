cmake_minimum_required(VERSION 3.14)
project(Prg2_Trees)

set(CMAKE_CXX_STANDARD 11)
include_directories(.)

add_executable(Prg2_demo main.cpp libs/BasicTree.cpp prglib.h)
