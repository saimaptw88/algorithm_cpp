add_library(ch10 SHARED
  chapter10.cpp
)

# tests
set(GTEST_ROOT /usr/local/)
include_directories(${GTEST_ROOT}/include/)
link_directories(${GTEST_ROOT}/lib/)
