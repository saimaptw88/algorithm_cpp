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
include src/CMakeFiles/my_app.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/my_app.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/my_app.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/my_app.dir/flags.make

src/CMakeFiles/my_app.dir/main.cpp.o: src/CMakeFiles/my_app.dir/flags.make
src/CMakeFiles/my_app.dir/main.cpp.o: /cpp-dev/src/main.cpp
src/CMakeFiles/my_app.dir/main.cpp.o: src/CMakeFiles/my_app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cpp-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/my_app.dir/main.cpp.o"
	cd /cpp-dev/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/my_app.dir/main.cpp.o -MF CMakeFiles/my_app.dir/main.cpp.o.d -o CMakeFiles/my_app.dir/main.cpp.o -c /cpp-dev/src/main.cpp

src/CMakeFiles/my_app.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_app.dir/main.cpp.i"
	cd /cpp-dev/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cpp-dev/src/main.cpp > CMakeFiles/my_app.dir/main.cpp.i

src/CMakeFiles/my_app.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_app.dir/main.cpp.s"
	cd /cpp-dev/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cpp-dev/src/main.cpp -o CMakeFiles/my_app.dir/main.cpp.s

src/CMakeFiles/my_app.dir/chapter4.cpp.o: src/CMakeFiles/my_app.dir/flags.make
src/CMakeFiles/my_app.dir/chapter4.cpp.o: /cpp-dev/src/chapter4.cpp
src/CMakeFiles/my_app.dir/chapter4.cpp.o: src/CMakeFiles/my_app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cpp-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/my_app.dir/chapter4.cpp.o"
	cd /cpp-dev/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/my_app.dir/chapter4.cpp.o -MF CMakeFiles/my_app.dir/chapter4.cpp.o.d -o CMakeFiles/my_app.dir/chapter4.cpp.o -c /cpp-dev/src/chapter4.cpp

src/CMakeFiles/my_app.dir/chapter4.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_app.dir/chapter4.cpp.i"
	cd /cpp-dev/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cpp-dev/src/chapter4.cpp > CMakeFiles/my_app.dir/chapter4.cpp.i

src/CMakeFiles/my_app.dir/chapter4.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_app.dir/chapter4.cpp.s"
	cd /cpp-dev/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cpp-dev/src/chapter4.cpp -o CMakeFiles/my_app.dir/chapter4.cpp.s

src/CMakeFiles/my_app.dir/chapter1.cpp.o: src/CMakeFiles/my_app.dir/flags.make
src/CMakeFiles/my_app.dir/chapter1.cpp.o: /cpp-dev/src/chapter1.cpp
src/CMakeFiles/my_app.dir/chapter1.cpp.o: src/CMakeFiles/my_app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cpp-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/my_app.dir/chapter1.cpp.o"
	cd /cpp-dev/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/my_app.dir/chapter1.cpp.o -MF CMakeFiles/my_app.dir/chapter1.cpp.o.d -o CMakeFiles/my_app.dir/chapter1.cpp.o -c /cpp-dev/src/chapter1.cpp

src/CMakeFiles/my_app.dir/chapter1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_app.dir/chapter1.cpp.i"
	cd /cpp-dev/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cpp-dev/src/chapter1.cpp > CMakeFiles/my_app.dir/chapter1.cpp.i

src/CMakeFiles/my_app.dir/chapter1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_app.dir/chapter1.cpp.s"
	cd /cpp-dev/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cpp-dev/src/chapter1.cpp -o CMakeFiles/my_app.dir/chapter1.cpp.s

src/CMakeFiles/my_app.dir/chapter2.cpp.o: src/CMakeFiles/my_app.dir/flags.make
src/CMakeFiles/my_app.dir/chapter2.cpp.o: /cpp-dev/src/chapter2.cpp
src/CMakeFiles/my_app.dir/chapter2.cpp.o: src/CMakeFiles/my_app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cpp-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/my_app.dir/chapter2.cpp.o"
	cd /cpp-dev/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/my_app.dir/chapter2.cpp.o -MF CMakeFiles/my_app.dir/chapter2.cpp.o.d -o CMakeFiles/my_app.dir/chapter2.cpp.o -c /cpp-dev/src/chapter2.cpp

src/CMakeFiles/my_app.dir/chapter2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_app.dir/chapter2.cpp.i"
	cd /cpp-dev/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cpp-dev/src/chapter2.cpp > CMakeFiles/my_app.dir/chapter2.cpp.i

src/CMakeFiles/my_app.dir/chapter2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_app.dir/chapter2.cpp.s"
	cd /cpp-dev/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cpp-dev/src/chapter2.cpp -o CMakeFiles/my_app.dir/chapter2.cpp.s

src/CMakeFiles/my_app.dir/chapter3.cpp.o: src/CMakeFiles/my_app.dir/flags.make
src/CMakeFiles/my_app.dir/chapter3.cpp.o: /cpp-dev/src/chapter3.cpp
src/CMakeFiles/my_app.dir/chapter3.cpp.o: src/CMakeFiles/my_app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cpp-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/my_app.dir/chapter3.cpp.o"
	cd /cpp-dev/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/my_app.dir/chapter3.cpp.o -MF CMakeFiles/my_app.dir/chapter3.cpp.o.d -o CMakeFiles/my_app.dir/chapter3.cpp.o -c /cpp-dev/src/chapter3.cpp

src/CMakeFiles/my_app.dir/chapter3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_app.dir/chapter3.cpp.i"
	cd /cpp-dev/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cpp-dev/src/chapter3.cpp > CMakeFiles/my_app.dir/chapter3.cpp.i

src/CMakeFiles/my_app.dir/chapter3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_app.dir/chapter3.cpp.s"
	cd /cpp-dev/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cpp-dev/src/chapter3.cpp -o CMakeFiles/my_app.dir/chapter3.cpp.s

# Object files for target my_app
my_app_OBJECTS = \
"CMakeFiles/my_app.dir/main.cpp.o" \
"CMakeFiles/my_app.dir/chapter4.cpp.o" \
"CMakeFiles/my_app.dir/chapter1.cpp.o" \
"CMakeFiles/my_app.dir/chapter2.cpp.o" \
"CMakeFiles/my_app.dir/chapter3.cpp.o"

# External object files for target my_app
my_app_EXTERNAL_OBJECTS =

src/my_app: src/CMakeFiles/my_app.dir/main.cpp.o
src/my_app: src/CMakeFiles/my_app.dir/chapter4.cpp.o
src/my_app: src/CMakeFiles/my_app.dir/chapter1.cpp.o
src/my_app: src/CMakeFiles/my_app.dir/chapter2.cpp.o
src/my_app: src/CMakeFiles/my_app.dir/chapter3.cpp.o
src/my_app: src/CMakeFiles/my_app.dir/build.make
src/my_app: src/libch05.so
src/my_app: src/libdp.so
src/my_app: src/CMakeFiles/my_app.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cpp-dev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable my_app"
	cd /cpp-dev/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/my_app.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/my_app.dir/build: src/my_app
.PHONY : src/CMakeFiles/my_app.dir/build

src/CMakeFiles/my_app.dir/clean:
	cd /cpp-dev/build/src && $(CMAKE_COMMAND) -P CMakeFiles/my_app.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/my_app.dir/clean

src/CMakeFiles/my_app.dir/depend:
	cd /cpp-dev/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cpp-dev /cpp-dev/src /cpp-dev/build /cpp-dev/build/src /cpp-dev/build/src/CMakeFiles/my_app.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/my_app.dir/depend

