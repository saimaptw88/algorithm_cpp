add_library(dp SHARED
  dp.cc
)

# tests
set(GTEST_ROOT /usr/local/)
include_directories(${GTEST_ROOT}/include/)
link_directories(${GTEST_ROOT}/lib/)

add_executable(dp_test ${CMAKE_CURRENT_SOURCE_DIR}/dp_test.cc)
target_link_libraries(dp_test dp gtest gtest_main pthread)
