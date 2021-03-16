cmake_minimum_required(VERSION 3.12)
project(technopark_cpp)
project(tests CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_REQUIRED ON)
set(CMAKE_C_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)

include_directories("${PROJECT_SOURCE_DIR}/include")

file(GLOB sources
        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/src/*.c")

add_library(tp_library STATIC ${sources})
add_executable(technopark_cpp ${sources})
target_link_libraries(technopark_cpp ${GTEST_LIBRARIES} -lpthread)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
message("OK: ${GTEST_LIBRARIES}")

file(GLOB test_sources
        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/test/*.cpp")

add_executable(tests ${test_sources})

enable_testing()

add_test(gtest ${EXECUTABLE_OUTPUT_PATH}/tests)
add_definitions(-fprofile-arcs -ftest-coverage)
target_link_libraries(tests -fprofile-arcs)
target_link_libraries(tests ${GTEST_LIBRARIES} pthread)
target_link_libraries(tests tp_library)