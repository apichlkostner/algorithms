cmake_minimum_required (VERSION 3.5)

project (dijkstra)

include_directories("${PROJECT_BINARY_DIR}")

set(CXX_FLAGS "-std=c++1z -Og -Wall")
set(CMAKE_CXX_FLAGS "${CXX_FLAGS}")

# to enable colors with ninja
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    add_compile_options (-fdiagnostics-color=always)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    add_compile_options (-fcolor-diagnostics)
endif ()

add_executable(dijkstra src/dijkstra.cpp src/main.cpp)

target_link_libraries (dijkstra)