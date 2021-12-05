cmake_minimum_required (VERSION 3.20)

project (Brickjoon)
set(CMAKE_SOURCE_DIR /Brickjoon)
set(CMAKE_BUILD_DIR /build)
set(CMAKE_BUILD_TYPE DEBUG_CONFIGURATIONS)
set(CURRENT_SOURCE_DIR "Brickjoon")

include_directories("include/")

add_subdirectory(Brickjoon)
