# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bartoszl/Programming/myProjects/Snake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bartoszl/Programming/myProjects/Snake/build

# Include any dependencies generated for this target.
include CMakeFiles/Snake-lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Snake-lib.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Snake-lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Snake-lib.dir/flags.make

CMakeFiles/Snake-lib.dir/Food.cpp.o: CMakeFiles/Snake-lib.dir/flags.make
CMakeFiles/Snake-lib.dir/Food.cpp.o: ../Food.cpp
CMakeFiles/Snake-lib.dir/Food.cpp.o: CMakeFiles/Snake-lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bartoszl/Programming/myProjects/Snake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Snake-lib.dir/Food.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Snake-lib.dir/Food.cpp.o -MF CMakeFiles/Snake-lib.dir/Food.cpp.o.d -o CMakeFiles/Snake-lib.dir/Food.cpp.o -c /home/bartoszl/Programming/myProjects/Snake/Food.cpp

CMakeFiles/Snake-lib.dir/Food.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Snake-lib.dir/Food.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bartoszl/Programming/myProjects/Snake/Food.cpp > CMakeFiles/Snake-lib.dir/Food.cpp.i

CMakeFiles/Snake-lib.dir/Food.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Snake-lib.dir/Food.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bartoszl/Programming/myProjects/Snake/Food.cpp -o CMakeFiles/Snake-lib.dir/Food.cpp.s

# Object files for target Snake-lib
Snake__lib_OBJECTS = \
"CMakeFiles/Snake-lib.dir/Food.cpp.o"

# External object files for target Snake-lib
Snake__lib_EXTERNAL_OBJECTS =

libSnake-lib.a: CMakeFiles/Snake-lib.dir/Food.cpp.o
libSnake-lib.a: CMakeFiles/Snake-lib.dir/build.make
libSnake-lib.a: CMakeFiles/Snake-lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bartoszl/Programming/myProjects/Snake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libSnake-lib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/Snake-lib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Snake-lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Snake-lib.dir/build: libSnake-lib.a
.PHONY : CMakeFiles/Snake-lib.dir/build

CMakeFiles/Snake-lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Snake-lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Snake-lib.dir/clean

CMakeFiles/Snake-lib.dir/depend:
	cd /home/bartoszl/Programming/myProjects/Snake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bartoszl/Programming/myProjects/Snake /home/bartoszl/Programming/myProjects/Snake /home/bartoszl/Programming/myProjects/Snake/build /home/bartoszl/Programming/myProjects/Snake/build /home/bartoszl/Programming/myProjects/Snake/build/CMakeFiles/Snake-lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Snake-lib.dir/depend

