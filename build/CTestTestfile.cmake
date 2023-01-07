# CMake generated Testfile for 
# Source directory: /cpp-dev
# Build directory: /cpp-dev/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[MyTest]=] "bash" "-c" "./src/ch05TEST")
set_tests_properties([=[MyTest]=] PROPERTIES  _BACKTRACE_TRIPLES "/cpp-dev/CMakeLists.txt;8;add_test;/cpp-dev/CMakeLists.txt;0;")
subdirs("src")
