cmake_minimum_required (VERSION 3.5.1 FATAL_ERROR)


add_subdirectory(./unit_test)

project(comanche-mdfixobd CXX)

add_definitions(${GCC_COVERAGE_COMPILE_FLAGS} -DCONFIG_DEBUG)

include_directories(${TBB_INCLUDE_DIRS})

file(GLOB SOURCES src/*.cpp)

add_library(${PROJECT_NAME} SHARED ${SOURCES})

set(CMAKE_SHARED_LINKER_FLAGS "-Wl,--no-undefined")
target_link_libraries(${PROJECT_NAME} common comanche-core pthread numa dl rt ${TBB_LIBRARIES})

# set the linkage in the install/lib
set_target_properties(${PROJECT_NAME} PROPERTIES 
                          INSTALL_RPATH ${CMAKE_INSTALL_PREFIX}/lib)
install (TARGETS ${PROJECT_NAME}
    LIBRARY 
    DESTINATION lib)


