cmake_minimum_required(VERSION 3.24)
project(MYALGORITHM)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)

enable_testing()
add_test(NAME MyTest COMMAND bash -c "./src/ch05_test")
