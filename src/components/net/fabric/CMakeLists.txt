cmake_minimum_required (VERSION 3.5.1 FATAL_ERROR)

add_compile_options(-g)

include(./.cmakeinclude)

add_subdirectory(./unit_test)

project(comanche-fabric CXX)

add_definitions(${GCC_COVERAGE_COMPILE_FLAGS} -DCONFIG_DEBUG)

file(GLOB SOURCES src/*.cpp)

add_library(${PROJECT_NAME} SHARED ${SOURCES})

set(CMAKE_SHARED_LINKER_FLAGS "-Wl,--no-undefined")

target_link_libraries(${PROJECT_NAME} common comanche-core fabric pthread)
# target_link_libraries(${PROJECT_NAME} common comanche-core pthread numa dl rt z rdmacm ibverbs)

