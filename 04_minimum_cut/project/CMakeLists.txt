cmake_minimum_required (VERSION 3.5)

project (random_contraction)

include_directories("${PROJECT_BINARY_DIR}")

set(CXX_FLAGS "-std=c++14 -O3 -Wall")
set(CMAKE_CXX_FLAGS "${CXX_FLAGS}")

add_executable(random_contraction src/Graph.cpp src/main.cpp)

target_link_libraries (random_contraction)