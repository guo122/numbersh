cmake_minimum_required (VERSION 3.0.2)

project(numbersh)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 1)

set(CMAKE_ROOT_DIR "${CMAKE_CURRENT_LIST_DIR}")
set(CMAKE_THIRDLIB_ROOTDIR ${CMAKE_ROOT_DIR}/3rdlib)

include(${CMAKE_ROOT_DIR}/BuildScript/cmake/Build.cmake)

# enable project folders
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMake")

#######################
set(_test 0)

add_compile_options(-std=c++1y)

add_subdirectory("3rd/pugixml")
add_subdirectory("3rd/mlTime")
add_subdirectory("3rd/mlPath")
add_subdirectory("3rd/mlLog")
add_subdirectory("3rd/mlCmd")

add_subdirectory("Code/Goblin")
