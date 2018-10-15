cmake_minimum_required(VERSION 3.0.0)
project(debsapp VERSION 0.1.0)

add_executable(debsapp main.cpp)
set_target_properties(debsapp PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
