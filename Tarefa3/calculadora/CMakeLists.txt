cmake_minimum_required(VERSION 3.17)
project(calculadora C)

set(CMAKE_C_STANDARD 99)

add_executable(calculadora main.c)
target_link_libraries(calculadora m)