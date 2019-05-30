cmake_minimum_required(VERSION 3.0.0)
project(compcode VERSION 0.1.0)

# GTest
#########################################################################
ADD_SUBDIRECTORY (googletest-master)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
########################################################################

add_executable(compcode main.cpp)

target_link_libraries(compcode gtest gtest_main)
add_test( compcode compcode )
