cmake_minimum_required(VERSION 3.12)
project(technopark_cpp)
project(tests CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_REQUIRED ON)
#set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)
set(CMAKE_C_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)

#configure_file(CMakeLists.txt.in
#        googletest-download/CMakeLists.txt)
#execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
#        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
#execute_process(COMMAND ${CMAKE_COMMAND} --build .
#        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )


#if ("${TARGET_CPU}" STREQUAL "amd64")
#    set (CMAKE_SIZEOF_VOID_P 8)
#
#    set_property (GLOBAL PROPERTY FIND_LIBRARY_USE_LIB64_PATHS TRUE)
#    set_property (GLOBAL PROPERTY FIND_LIBRARY_USE_LIB32_PATHS FALSE)
#elseif ("${TARGET_CPU}" STREQUAL "x86")
#    set (CMAKE_SIZEOF_VOID_P 4)
#
#    set_property (GLOBAL PROPERTY FIND_LIBRARY_USE_LIB64_PATHS FALSE)
#    set_property (GLOBAL PROPERTY FIND_LIBRARY_USE_LIB32_PATHS TRUE)
#
#    if (GCC)
#        set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32")
#        set (CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} -m32")
#    endif ()
#endif ()

#
#add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
#        ${CMAKE_BINARY_DIR}/googletest-build)
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

#add_subdirectory(test)

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
#add_executable(technopark_cpp test/main.cpp)


#if (CMAKE_BUILD_TYPE MATCHES Debug)
#    include(CodeCoverage)
#    append_coverage_compiler_flags()
#    setup_target_for_coverage_lcov(
#            NAME coverage
#            EXECUTABLE ctest
#            BASE_DIRECTORY "${PROJECT_SOURCE_DIR}"
#            EXCLUDE "build/*" "test/*" "src/main.c" "src/date_parser.c")
#endif()













#cmake_minimum_required(VERSION 3.12)
#project(technopark_cpp)
#
#set(CMAKE_C_STANDARD 99)
#set(CMAKE_CXX_REQUIRED ON)
#set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)
#set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
#set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)
#
#configure_file(CMakeLists.txt.in
#        googletest-download/CMakeLists.txt)
##execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
##        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
##execute_process(COMMAND ${CMAKE_COMMAND} --build .
##        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
#
#
#if ("${TARGET_CPU}" STREQUAL "amd64")
#    set (CMAKE_SIZEOF_VOID_P 8)
#
#    set_property (GLOBAL PROPERTY FIND_LIBRARY_USE_LIB64_PATHS TRUE)
#    set_property (GLOBAL PROPERTY FIND_LIBRARY_USE_LIB32_PATHS FALSE)
#elseif ("${TARGET_CPU}" STREQUAL "x86")
#    set (CMAKE_SIZEOF_VOID_P 4)
#
#    set_property (GLOBAL PROPERTY FIND_LIBRARY_USE_LIB64_PATHS FALSE)
#    set_property (GLOBAL PROPERTY FIND_LIBRARY_USE_LIB32_PATHS TRUE)
#
#    if (GCC)
#        set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32")
#        set (CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} -m32")
#    endif ()
#endif ()
#
##add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
##        ${CMAKE_BINARY_DIR}/googletest-build)
#
#include_directories("${PROJECT_SOURCE_DIR}/include")
#
#file(GLOB sources
#        "${PROJECT_SOURCE_DIR}/include/*.h"
#        "${PROJECT_SOURCE_DIR}/src/*.c")
#
#
#enable_testing()
#
#find_package(GTest REQUIRED)
#include_directories(${GTEST_INCLUDE_DIRS})
#message("OK: ${GTEST_LIBRARIES}")
#message(${GTEST_INCLUDE_DIRS})
#
#add_subdirectory(test)
#
##file(GLOB test_sources
##        "${PROJECT_SOURCE_DIR}/include/*.h"
##        "${PROJECT_SOURCE_DIR}/test/*.cpp")
#
##add_executable(testing ${test_sources})
##target_link_libraries(testing ${GTEST_LIBRARIES} -lpthread)
#
#add_executable(technopark_cpp ${sources})
#target_link_libraries(technopark_cpp ${GTEST_LIBRARIES} -lpthread)
#
#if (CMAKE_BUILD_TYPE MATCHES Debug)
#    include(CodeCoverage)
#    append_coverage_compiler_flags()
#    setup_target_for_coverage_lcov(
#            NAME coverage
#            EXECUTABLE ctest
#            BASE_DIRECTORY "${PROJECT_SOURCE_DIR}"
#            EXCLUDE "build/*" "test/*" "src/main.c" "src/date_parser.c")
#endif()