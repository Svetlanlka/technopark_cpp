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
CMAKE_COMMAND = /snap/clion/145/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/145/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/svetlana/tp/technopark_cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/svetlana/tp/technopark_cpp/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/tp_library.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tp_library.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tp_library.dir/flags.make

CMakeFiles/tp_library.dir/src/date_filter.c.o: CMakeFiles/tp_library.dir/flags.make
CMakeFiles/tp_library.dir/src/date_filter.c.o: ../src/date_filter.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/svetlana/tp/technopark_cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/tp_library.dir/src/date_filter.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tp_library.dir/src/date_filter.c.o   -c /home/svetlana/tp/technopark_cpp/src/date_filter.c

CMakeFiles/tp_library.dir/src/date_filter.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tp_library.dir/src/date_filter.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/svetlana/tp/technopark_cpp/src/date_filter.c > CMakeFiles/tp_library.dir/src/date_filter.c.i

CMakeFiles/tp_library.dir/src/date_filter.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tp_library.dir/src/date_filter.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/svetlana/tp/technopark_cpp/src/date_filter.c -o CMakeFiles/tp_library.dir/src/date_filter.c.s

CMakeFiles/tp_library.dir/src/main.c.o: CMakeFiles/tp_library.dir/flags.make
CMakeFiles/tp_library.dir/src/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/svetlana/tp/technopark_cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/tp_library.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tp_library.dir/src/main.c.o   -c /home/svetlana/tp/technopark_cpp/src/main.c

CMakeFiles/tp_library.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tp_library.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/svetlana/tp/technopark_cpp/src/main.c > CMakeFiles/tp_library.dir/src/main.c.i

CMakeFiles/tp_library.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tp_library.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/svetlana/tp/technopark_cpp/src/main.c -o CMakeFiles/tp_library.dir/src/main.c.s

# Object files for target tp_library
tp_library_OBJECTS = \
"CMakeFiles/tp_library.dir/src/date_filter.c.o" \
"CMakeFiles/tp_library.dir/src/main.c.o"

# External object files for target tp_library
tp_library_EXTERNAL_OBJECTS =

libtp_library.a: CMakeFiles/tp_library.dir/src/date_filter.c.o
libtp_library.a: CMakeFiles/tp_library.dir/src/main.c.o
libtp_library.a: CMakeFiles/tp_library.dir/build.make
libtp_library.a: CMakeFiles/tp_library.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/svetlana/tp/technopark_cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C static library libtp_library.a"
	$(CMAKE_COMMAND) -P CMakeFiles/tp_library.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tp_library.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tp_library.dir/build: libtp_library.a

.PHONY : CMakeFiles/tp_library.dir/build

CMakeFiles/tp_library.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tp_library.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tp_library.dir/clean

CMakeFiles/tp_library.dir/depend:
	cd /home/svetlana/tp/technopark_cpp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/svetlana/tp/technopark_cpp /home/svetlana/tp/technopark_cpp /home/svetlana/tp/technopark_cpp/cmake-build-debug /home/svetlana/tp/technopark_cpp/cmake-build-debug /home/svetlana/tp/technopark_cpp/cmake-build-debug/CMakeFiles/tp_library.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tp_library.dir/depend

