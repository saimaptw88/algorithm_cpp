add_library(ch08 SHARED
  chapter8.cpp
)

# tests
set(GTEST_ROOT /usr/local/)
include_directories(${GTEST_ROOT}/include/)
link_directories(${GTEST_ROOT}/lib/)

add_executable(ch08_test ${CMAKE_CURRENT_SOURCE_DIR}/chapter8_test.cpp)
target_link_libraries(ch08_test ch08 gtest gtest_main pthread)
