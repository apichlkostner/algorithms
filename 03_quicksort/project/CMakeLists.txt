cmake_minimum_required (VERSION 3.5)

project (quicksort)

include_directories("${PROJECT_BINARY_DIR}")

set(CXX_FLAGS "-std=c++11 -O3 -Wall")
set(CMAKE_CXX_FLAGS "${CXX_FLAGS}")

add_executable(quicksort src/Quicksort.cpp src/main.cpp)

target_link_libraries (quicksort)