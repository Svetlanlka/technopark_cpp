# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/svetlana/tp/technopark_cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/svetlana/tp/technopark_cpp/build

# Include any dependencies generated for this target.
include test/CMakeFiles/date_parser_test_tests.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/date_parser_test_tests.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/date_parser_test_tests.dir/flags.make

test/CMakeFiles/date_parser_test_tests.dir/__/src/date_parser.c.o: test/CMakeFiles/date_parser_test_tests.dir/flags.make
test/CMakeFiles/date_parser_test_tests.dir/__/src/date_parser.c.o: ../src/date_parser.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/svetlana/tp/technopark_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object test/CMakeFiles/date_parser_test_tests.dir/__/src/date_parser.c.o"
	cd /home/svetlana/tp/technopark_cpp/build/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/date_parser_test_tests.dir/__/src/date_parser.c.o   -c /home/svetlana/tp/technopark_cpp/src/date_parser.c

test/CMakeFiles/date_parser_test_tests.dir/__/src/date_parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/date_parser_test_tests.dir/__/src/date_parser.c.i"
	cd /home/svetlana/tp/technopark_cpp/build/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/svetlana/tp/technopark_cpp/src/date_parser.c > CMakeFiles/date_parser_test_tests.dir/__/src/date_parser.c.i

test/CMakeFiles/date_parser_test_tests.dir/__/src/date_parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/date_parser_test_tests.dir/__/src/date_parser.c.s"
	cd /home/svetlana/tp/technopark_cpp/build/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/svetlana/tp/technopark_cpp/src/date_parser.c -o CMakeFiles/date_parser_test_tests.dir/__/src/date_parser.c.s

test/CMakeFiles/date_parser_test_tests.dir/date_parser_test.cpp.o: test/CMakeFiles/date_parser_test_tests.dir/flags.make
test/CMakeFiles/date_parser_test_tests.dir/date_parser_test.cpp.o: ../test/date_parser_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/svetlana/tp/technopark_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/CMakeFiles/date_parser_test_tests.dir/date_parser_test.cpp.o"
	cd /home/svetlana/tp/technopark_cpp/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/date_parser_test_tests.dir/date_parser_test.cpp.o -c /home/svetlana/tp/technopark_cpp/test/date_parser_test.cpp

test/CMakeFiles/date_parser_test_tests.dir/date_parser_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/date_parser_test_tests.dir/date_parser_test.cpp.i"
	cd /home/svetlana/tp/technopark_cpp/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/svetlana/tp/technopark_cpp/test/date_parser_test.cpp > CMakeFiles/date_parser_test_tests.dir/date_parser_test.cpp.i

test/CMakeFiles/date_parser_test_tests.dir/date_parser_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/date_parser_test_tests.dir/date_parser_test.cpp.s"
	cd /home/svetlana/tp/technopark_cpp/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/svetlana/tp/technopark_cpp/test/date_parser_test.cpp -o CMakeFiles/date_parser_test_tests.dir/date_parser_test.cpp.s

test/CMakeFiles/date_parser_test_tests.dir/main.cpp.o: test/CMakeFiles/date_parser_test_tests.dir/flags.make
test/CMakeFiles/date_parser_test_tests.dir/main.cpp.o: ../test/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/svetlana/tp/technopark_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object test/CMakeFiles/date_parser_test_tests.dir/main.cpp.o"
	cd /home/svetlana/tp/technopark_cpp/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/date_parser_test_tests.dir/main.cpp.o -c /home/svetlana/tp/technopark_cpp/test/main.cpp

test/CMakeFiles/date_parser_test_tests.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/date_parser_test_tests.dir/main.cpp.i"
	cd /home/svetlana/tp/technopark_cpp/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/svetlana/tp/technopark_cpp/test/main.cpp > CMakeFiles/date_parser_test_tests.dir/main.cpp.i

test/CMakeFiles/date_parser_test_tests.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/date_parser_test_tests.dir/main.cpp.s"
	cd /home/svetlana/tp/technopark_cpp/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/svetlana/tp/technopark_cpp/test/main.cpp -o CMakeFiles/date_parser_test_tests.dir/main.cpp.s

# Object files for target date_parser_test_tests
date_parser_test_tests_OBJECTS = \
"CMakeFiles/date_parser_test_tests.dir/__/src/date_parser.c.o" \
"CMakeFiles/date_parser_test_tests.dir/date_parser_test.cpp.o" \
"CMakeFiles/date_parser_test_tests.dir/main.cpp.o"

# External object files for target date_parser_test_tests
date_parser_test_tests_EXTERNAL_OBJECTS =

test/date_parser_test_tests: test/CMakeFiles/date_parser_test_tests.dir/__/src/date_parser.c.o
test/date_parser_test_tests: test/CMakeFiles/date_parser_test_tests.dir/date_parser_test.cpp.o
test/date_parser_test_tests: test/CMakeFiles/date_parser_test_tests.dir/main.cpp.o
test/date_parser_test_tests: test/CMakeFiles/date_parser_test_tests.dir/build.make
test/date_parser_test_tests: googletest-build/googlemock/gtest/libgtest_main.a
test/date_parser_test_tests: googletest-build/googlemock/gtest/libgtest.a
test/date_parser_test_tests: test/CMakeFiles/date_parser_test_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/svetlana/tp/technopark_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable date_parser_test_tests"
	cd /home/svetlana/tp/technopark_cpp/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/date_parser_test_tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/date_parser_test_tests.dir/build: test/date_parser_test_tests

.PHONY : test/CMakeFiles/date_parser_test_tests.dir/build

test/CMakeFiles/date_parser_test_tests.dir/clean:
	cd /home/svetlana/tp/technopark_cpp/build/test && $(CMAKE_COMMAND) -P CMakeFiles/date_parser_test_tests.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/date_parser_test_tests.dir/clean

test/CMakeFiles/date_parser_test_tests.dir/depend:
	cd /home/svetlana/tp/technopark_cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/svetlana/tp/technopark_cpp /home/svetlana/tp/technopark_cpp/test /home/svetlana/tp/technopark_cpp/build /home/svetlana/tp/technopark_cpp/build/test /home/svetlana/tp/technopark_cpp/build/test/CMakeFiles/date_parser_test_tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/date_parser_test_tests.dir/depend

