# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cpp-dev

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cpp-dev/build

# Include any dependencies generated for this target.
include src/dp/CMakeFiles/dp_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/dp/CMakeFiles/dp_test.dir/compiler_depend.make

# Include the progress variables for this target.
include src/dp/CMakeFiles/dp_test.dir/progress.make

# Include the compile flags for this target's objects.
include src/dp/CMakeFiles/dp_test.dir/flags.make

src/dp/CMakeFiles/dp_test.dir/dp_test.cc.o: src/dp/CMakeFiles/dp_test.dir/flags.make
src/dp/CMakeFiles/dp_test.dir/dp_test.cc.o: /cpp-dev/src/dp/dp_test.cc
src/dp/CMakeFiles/dp_test.dir/dp_test.cc.o: src/dp/CMakeFiles/dp_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cpp-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/dp/CMakeFiles/dp_test.dir/dp_test.cc.o"
	cd /cpp-dev/build/src/dp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/dp/CMakeFiles/dp_test.dir/dp_test.cc.o -MF CMakeFiles/dp_test.dir/dp_test.cc.o.d -o CMakeFiles/dp_test.dir/dp_test.cc.o -c /cpp-dev/src/dp/dp_test.cc

src/dp/CMakeFiles/dp_test.dir/dp_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dp_test.dir/dp_test.cc.i"
	cd /cpp-dev/build/src/dp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cpp-dev/src/dp/dp_test.cc > CMakeFiles/dp_test.dir/dp_test.cc.i

src/dp/CMakeFiles/dp_test.dir/dp_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dp_test.dir/dp_test.cc.s"
	cd /cpp-dev/build/src/dp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cpp-dev/src/dp/dp_test.cc -o CMakeFiles/dp_test.dir/dp_test.cc.s

# Object files for target dp_test
dp_test_OBJECTS = \
"CMakeFiles/dp_test.dir/dp_test.cc.o"

# External object files for target dp_test
dp_test_EXTERNAL_OBJECTS =

src/dp_test: src/dp/CMakeFiles/dp_test.dir/dp_test.cc.o
src/dp_test: src/dp/CMakeFiles/dp_test.dir/build.make
src/dp_test: src/libdp.so
src/dp_test: src/dp/CMakeFiles/dp_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cpp-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../dp_test"
	cd /cpp-dev/build/src/dp && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dp_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/dp/CMakeFiles/dp_test.dir/build: src/dp_test
.PHONY : src/dp/CMakeFiles/dp_test.dir/build

src/dp/CMakeFiles/dp_test.dir/clean:
	cd /cpp-dev/build/src/dp && $(CMAKE_COMMAND) -P CMakeFiles/dp_test.dir/cmake_clean.cmake
.PHONY : src/dp/CMakeFiles/dp_test.dir/clean

src/dp/CMakeFiles/dp_test.dir/depend:
	cd /cpp-dev/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cpp-dev /cpp-dev/src/dp /cpp-dev/build /cpp-dev/build/src/dp /cpp-dev/build/src/dp/CMakeFiles/dp_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/dp/CMakeFiles/dp_test.dir/depend
