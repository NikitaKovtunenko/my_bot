cmake_minimum_required(VERSION 3.10.2)
project(tests)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(GTEST_ROOT "/Users/kiton/Library/gTest/googletest")
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_executable(tests TestLogger.cpp)
target_link_libraries(tests PRIVATE ${GTEST_BOTH_LIBRARIES})