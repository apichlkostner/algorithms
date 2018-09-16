cmake_minimum_required (VERSION 3.5)

project (inversion_test)

enable_testing()
find_package(GTest REQUIRED)

add_test(AllTests inversion_test)

include_directories("${GTEST_INCLUDE_DIRS} ${PROJECT_BINARY_DIR}" "../project/src")

set(CXX_FLAGS "-std=c++11 -O3 -Wall")
set(CMAKE_CXX_FLAGS "${CXX_FLAGS}")
 
add_executable(inversion_test test.cpp ../project/src/ArrayInversion.cpp)

target_link_libraries (inversion_test ${GTEST_BOTH_LIBRARIES} pthread)