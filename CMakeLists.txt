cmake_minimum_required(VERSION 3.16)
project(technopark_cpp C)

set(CMAKE_C_STANDARD 99)

include_directories(include)

file(GLOB sources
        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/src/*.c")

add_executable(technopark_cpp ${sources})