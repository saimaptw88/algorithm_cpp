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
include src/ch07/CMakeFiles/ch07.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/ch07/CMakeFiles/ch07.dir/compiler_depend.make

# Include the progress variables for this target.
include src/ch07/CMakeFiles/ch07.dir/progress.make

# Include the compile flags for this target's objects.
include src/ch07/CMakeFiles/ch07.dir/flags.make

src/ch07/CMakeFiles/ch07.dir/chapter7.cpp.o: src/ch07/CMakeFiles/ch07.dir/flags.make
src/ch07/CMakeFiles/ch07.dir/chapter7.cpp.o: /cpp-dev/src/ch07/chapter7.cpp
src/ch07/CMakeFiles/ch07.dir/chapter7.cpp.o: src/ch07/CMakeFiles/ch07.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cpp-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/ch07/CMakeFiles/ch07.dir/chapter7.cpp.o"
	cd /cpp-dev/build/src/ch07 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/ch07/CMakeFiles/ch07.dir/chapter7.cpp.o -MF CMakeFiles/ch07.dir/chapter7.cpp.o.d -o CMakeFiles/ch07.dir/chapter7.cpp.o -c /cpp-dev/src/ch07/chapter7.cpp

src/ch07/CMakeFiles/ch07.dir/chapter7.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ch07.dir/chapter7.cpp.i"
	cd /cpp-dev/build/src/ch07 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cpp-dev/src/ch07/chapter7.cpp > CMakeFiles/ch07.dir/chapter7.cpp.i

src/ch07/CMakeFiles/ch07.dir/chapter7.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ch07.dir/chapter7.cpp.s"
	cd /cpp-dev/build/src/ch07 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cpp-dev/src/ch07/chapter7.cpp -o CMakeFiles/ch07.dir/chapter7.cpp.s

# Object files for target ch07
ch07_OBJECTS = \
"CMakeFiles/ch07.dir/chapter7.cpp.o"

# External object files for target ch07
ch07_EXTERNAL_OBJECTS =

src/libch07.so: src/ch07/CMakeFiles/ch07.dir/chapter7.cpp.o
src/libch07.so: src/ch07/CMakeFiles/ch07.dir/build.make
src/libch07.so: src/ch07/CMakeFiles/ch07.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cpp-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library ../libch07.so"
	cd /cpp-dev/build/src/ch07 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ch07.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/ch07/CMakeFiles/ch07.dir/build: src/libch07.so
.PHONY : src/ch07/CMakeFiles/ch07.dir/build

src/ch07/CMakeFiles/ch07.dir/clean:
	cd /cpp-dev/build/src/ch07 && $(CMAKE_COMMAND) -P CMakeFiles/ch07.dir/cmake_clean.cmake
.PHONY : src/ch07/CMakeFiles/ch07.dir/clean

src/ch07/CMakeFiles/ch07.dir/depend:
	cd /cpp-dev/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cpp-dev /cpp-dev/src/ch07 /cpp-dev/build /cpp-dev/build/src/ch07 /cpp-dev/build/src/ch07/CMakeFiles/ch07.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/ch07/CMakeFiles/ch07.dir/depend

