cmake_minimum_required (VERSION 3.20)
#cmake req version

project (Brickjoon)
#cmake root project name

set(CMAKE_SOURCE_DIR /Brickjoon)
set(CMAKE_BUILD_DIR /build)
set(CMAKE_BUILD_TYPE DEBUG_CONFIGURATIONS)
set(CURRENT_SOURCE_DIR "Brickjoon")
#set env phase

include_directories("include/")
#include GNU compiler bits header

add_subdirectory(Brickjoon)
# source directory add

MESSAGE(STATUS "done : root/")
# root finish