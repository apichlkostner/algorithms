cmake_minimum_required (VERSION 3.5)

project (dijkstra_test)

enable_testing()
find_package(GTest REQUIRED)

add_test(AllTests rdijkstra_test)

include_directories("${GTEST_INCLUDE_DIRS} ${PROJECT_BINARY_DIR}" "../project/src")

set(CXX_FLAGS "-std=c++1z -O3 -Wall")
set(CMAKE_CXX_FLAGS "${CXX_FLAGS}")
 
add_executable(dijkstra_test test.cpp ../project/src/dijkstra.cpp)

target_link_libraries (dijkstra_test ${GTEST_BOTH_LIBRARIES} pthread)