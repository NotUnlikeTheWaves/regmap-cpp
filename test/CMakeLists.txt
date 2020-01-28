cmake_minimum_required(VERSION 3.0)
project(RegisterMapTests)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/googletest)

add_executable(test ${CMAKE_CURRENT_SOURCE_DIR}/test_registermap.cpp)
target_include_directories(test PUBLIC ${GTEST_INCLUDE_DIRS} ${RegisterMap_INCLUDE_DIRS})
target_link_libraries(test gtest gtest_main)

enable_testing()
add_test(registermap_test test)
