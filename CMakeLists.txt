# Generic CMake things
cmake_minimum_required(VERSION 3.0)
project(RegisterMap)
SET(CMAKE_CXX_STANDARD 11)

# Actual library portion
set(RegisterMap_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include)
add_library(registermap INTERFACE)
target_include_directories(registermap INTERFACE ${RegisterMap_INCLUDE_DIRS})

# Add tests
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/test)
