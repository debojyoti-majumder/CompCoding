cmake_minimum_required(VERSION 3.0.0)
project(leetcode VERSION 0.1.0)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(googletest)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})
add_executable(leetcode main.cpp)

target_link_libraries(leetcode gtest gtest_main gmock)
add_test( leetcode leetcode )