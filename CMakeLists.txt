cmake_minimum_required (VERSION 3.10)
project(CJJ_STL)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

if (GCOVR)
    message(STATUS "GCOVR enabled")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/STL)

add_subdirectory(test)