cmake_minimum_required(VERSION 2.8.12 FATAL_ERROR)
project(tbb_lab)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(tbb_lab ${SOURCE_FILES})

add_subdirectory(external/tbb)
target_link_libraries(tbb_lab tbb)