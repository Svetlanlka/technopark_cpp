cmake_minimum_required(VERSION 3.16)
project(technopark_cpp C)

set(CMAKE_C_STANDARD 99)

configure_file(CMakeLists.txt.in
        googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )

add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
        ${CMAKE_BINARY_DIR}/googletest-build)

enable_testing()
add_subdirectory(tests)

include_directories("${PROJECT_SOURCE_DIR}/include")

file(GLOB sources
        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/src/*.c"
        "${PROJECT_SOURCE_DIR}/tests/*.c")

add_executable(technopark_cpp ${sources})
