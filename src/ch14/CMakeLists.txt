add_library(ch14 SHARED
  chapter14.cpp
)

# tests
set(GTEST_ROOT /usr/local/)
include_directories(${GTEST_ROOT}/include/)
link_directories(${GTEST_ROOT}/lib/)
