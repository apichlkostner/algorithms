cmake_minimum_required (VERSION 3.5)

project (array_inversion)

include_directories("${PROJECT_BINARY_DIR}")

set(CXX_FLAGS "-std=c++11 -O3 -Wall")
set(CMAKE_CXX_FLAGS "${CXX_FLAGS}")

add_executable(array_inversion src/ArrayInversion.cpp src/main.cpp)

target_link_libraries (array_inversion)