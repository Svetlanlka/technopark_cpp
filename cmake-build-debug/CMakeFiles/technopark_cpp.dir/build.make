# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = /snap/clion/139/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/139/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/svetlana/tp/technopark_cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/svetlana/tp/technopark_cpp/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/technopark_cpp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/technopark_cpp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/technopark_cpp.dir/flags.make

CMakeFiles/technopark_cpp.dir/src/date_parser.c.o: CMakeFiles/technopark_cpp.dir/flags.make
CMakeFiles/technopark_cpp.dir/src/date_parser.c.o: ../src/date_parser.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/svetlana/tp/technopark_cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/technopark_cpp.dir/src/date_parser.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/technopark_cpp.dir/src/date_parser.c.o   -c /home/svetlana/tp/technopark_cpp/src/date_parser.c

CMakeFiles/technopark_cpp.dir/src/date_parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/technopark_cpp.dir/src/date_parser.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/svetlana/tp/technopark_cpp/src/date_parser.c > CMakeFiles/technopark_cpp.dir/src/date_parser.c.i

CMakeFiles/technopark_cpp.dir/src/date_parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/technopark_cpp.dir/src/date_parser.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/svetlana/tp/technopark_cpp/src/date_parser.c -o CMakeFiles/technopark_cpp.dir/src/date_parser.c.s

CMakeFiles/technopark_cpp.dir/src/main.c.o: CMakeFiles/technopark_cpp.dir/flags.make
CMakeFiles/technopark_cpp.dir/src/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/svetlana/tp/technopark_cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/technopark_cpp.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/technopark_cpp.dir/src/main.c.o   -c /home/svetlana/tp/technopark_cpp/src/main.c

CMakeFiles/technopark_cpp.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/technopark_cpp.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/svetlana/tp/technopark_cpp/src/main.c > CMakeFiles/technopark_cpp.dir/src/main.c.i

CMakeFiles/technopark_cpp.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/technopark_cpp.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/svetlana/tp/technopark_cpp/src/main.c -o CMakeFiles/technopark_cpp.dir/src/main.c.s

CMakeFiles/technopark_cpp.dir/tests/date_parser_test.c.o: CMakeFiles/technopark_cpp.dir/flags.make
CMakeFiles/technopark_cpp.dir/tests/date_parser_test.c.o: ../tests/date_parser_test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/svetlana/tp/technopark_cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/technopark_cpp.dir/tests/date_parser_test.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/technopark_cpp.dir/tests/date_parser_test.c.o   -c /home/svetlana/tp/technopark_cpp/tests/date_parser_test.c

CMakeFiles/technopark_cpp.dir/tests/date_parser_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/technopark_cpp.dir/tests/date_parser_test.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/svetlana/tp/technopark_cpp/tests/date_parser_test.c > CMakeFiles/technopark_cpp.dir/tests/date_parser_test.c.i

CMakeFiles/technopark_cpp.dir/tests/date_parser_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/technopark_cpp.dir/tests/date_parser_test.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/svetlana/tp/technopark_cpp/tests/date_parser_test.c -o CMakeFiles/technopark_cpp.dir/tests/date_parser_test.c.s

CMakeFiles/technopark_cpp.dir/tests/main.c.o: CMakeFiles/technopark_cpp.dir/flags.make
CMakeFiles/technopark_cpp.dir/tests/main.c.o: ../tests/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/svetlana/tp/technopark_cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/technopark_cpp.dir/tests/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/technopark_cpp.dir/tests/main.c.o   -c /home/svetlana/tp/technopark_cpp/tests/main.c

CMakeFiles/technopark_cpp.dir/tests/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/technopark_cpp.dir/tests/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/svetlana/tp/technopark_cpp/tests/main.c > CMakeFiles/technopark_cpp.dir/tests/main.c.i

CMakeFiles/technopark_cpp.dir/tests/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/technopark_cpp.dir/tests/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/svetlana/tp/technopark_cpp/tests/main.c -o CMakeFiles/technopark_cpp.dir/tests/main.c.s

# Object files for target technopark_cpp
technopark_cpp_OBJECTS = \
"CMakeFiles/technopark_cpp.dir/src/date_parser.c.o" \
"CMakeFiles/technopark_cpp.dir/src/main.c.o" \
"CMakeFiles/technopark_cpp.dir/tests/date_parser_test.c.o" \
"CMakeFiles/technopark_cpp.dir/tests/main.c.o"

# External object files for target technopark_cpp
technopark_cpp_EXTERNAL_OBJECTS =

technopark_cpp: CMakeFiles/technopark_cpp.dir/src/date_parser.c.o
technopark_cpp: CMakeFiles/technopark_cpp.dir/src/main.c.o
technopark_cpp: CMakeFiles/technopark_cpp.dir/tests/date_parser_test.c.o
technopark_cpp: CMakeFiles/technopark_cpp.dir/tests/main.c.o
technopark_cpp: CMakeFiles/technopark_cpp.dir/build.make
technopark_cpp: CMakeFiles/technopark_cpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/svetlana/tp/technopark_cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable technopark_cpp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/technopark_cpp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/technopark_cpp.dir/build: technopark_cpp

.PHONY : CMakeFiles/technopark_cpp.dir/build

CMakeFiles/technopark_cpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/technopark_cpp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/technopark_cpp.dir/clean

CMakeFiles/technopark_cpp.dir/depend:
	cd /home/svetlana/tp/technopark_cpp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/svetlana/tp/technopark_cpp /home/svetlana/tp/technopark_cpp /home/svetlana/tp/technopark_cpp/cmake-build-debug /home/svetlana/tp/technopark_cpp/cmake-build-debug /home/svetlana/tp/technopark_cpp/cmake-build-debug/CMakeFiles/technopark_cpp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/technopark_cpp.dir/depend

