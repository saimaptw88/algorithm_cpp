add_library(ch05 SHARED
  chapter5.cpp
)

# tests
set(GTEST_ROOT /usr/local/)
include_directories(${GTEST_ROOT}/include/)
link_directories(${GTEST_ROOT}/lib/)

add_executable(ch05_test ${CMAKE_CURRENT_SOURCE_DIR}/chapter5_test.cpp)
target_link_libraries(ch05_test ch05 gtest gtest_main pthread)
