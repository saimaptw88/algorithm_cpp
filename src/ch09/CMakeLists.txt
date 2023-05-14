add_library(ch09 SHARED
  chapter9.cpp
)

# tests
set(GTEST_ROOT /usr/local/)
include_directories(${GTEST_ROOT}/include/)
link_directories(${GTEST_ROOT}/lib/)

# add_executable(ch09_test ${CMAKE_CURRENT_SOURCE_DIR}/chapter9_test.cpp)
# target_link_libraries(ch09_test ch09 gtest gtest_main pthread)
