add_library(ch15 SHARED
  chapter15.cpp
)

# tests
set(GTEST_ROOT /usr/local/)
include_directories(${GTEST_ROOT}/include/)
link_directories(${GTEST_ROOT}/lib/)
