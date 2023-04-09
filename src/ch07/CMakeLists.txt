add_library(ch07 SHARED
  chapter7.cpp
)

# tests
set(GTEST_ROOT /usr/local/)
include_directories(${GTEST_ROOT}/include/)
link_directories(${GTEST_ROOT}/lib/)

add_executable(ch07_test ${CMAKE_CURRENT_SOURCE_DIR}/chapter7_test.cpp)
target_link_libraries(ch07_test ch07 gtest gtest_main pthread)
