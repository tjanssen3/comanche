cmake_minimum_required (VERSION 3.5.1 FATAL_ERROR)

project(regionpart-tests CXX)


find_library(GTEST_LIB NAMES GTEST PATHS /usr/local/lib,/usr/lib)

add_definitions(${GCC_COVERAGE_COMPILE_FLAGS} -DCONFIG_DEBUG)

add_executable(regionpart-test1 test1.cpp)
target_link_libraries(regionpart-test1 common numa gtest pthread dl comanche-partregion)
target_compile_features(regionpart-test1 PRIVATE cxx_range_for)
