
include_directories(
  "${CMAKE_SOURCE_DIR}/ch05"
)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory(ch05)
add_subdirectory(dp)
add_executable(my_app main.cpp chapter4.cpp chapter1.cpp chapter2.cpp chapter3.cpp)
target_link_libraries(my_app ch05 dp)
