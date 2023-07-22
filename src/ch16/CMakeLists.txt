add_library(ch16 SHARED
  chapter16.cpp
)

# tests
set(GTEST_ROOT /usr/local/)
include_directories(${GTEST_ROOT}/include/)
link_directories(${GTEST_ROOT}/lib/)
