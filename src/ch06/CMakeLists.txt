add_library(ch06 SHARED
  chapter6.cpp
)

# tests
set(GTEST_ROOT /usr/local/)
include_directories(${GTEST_ROOT}/include/)
link_directories(${GTEST_ROOT}/lib/)

add_executable(ch06_test ${CMAKE_CURRENT_SOURCE_DIR}/chapter6_test.cpp)
target_link_libraries(ch06_test ch06 gtest gtest_main pthread)
