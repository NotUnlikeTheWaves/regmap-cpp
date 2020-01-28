cmake_minimum_required(VERSION 3.0)
project(RegisterMapTests)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/googletest)

add_executable(tests ${CMAKE_CURRENT_SOURCE_DIR}/test_registermap.cpp)
target_include_directories(tests PUBLIC ${GTEST_INCLUDE_DIRS} ${RegisterMap_INCLUDE_DIRS})
target_link_libraries(tests gtest gtest_main)

enable_testing()
add_test(registermap_test tests)
