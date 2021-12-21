cmake_minimum_required (VERSION 3.20)
# cmake req version

project (Brickjoon)
# cmake root project name

set(CMAKE_SOURCE_DIR /Brickjoon)
set(CMAKE_BUILD_DIR /build)
set(CMAKE_BUILD_TYPE DEBUG_CONFIGURATIONS)
set(CURRENT_SOURCE_DIR "Brickjoon")
# set env phase
if(${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
	message(STATUS "MSVC detected include activate")
	include_directories("include/Mingw64/")

elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
	message(STATUS "Clang is not supported :( maybe soon")

elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
	message(STATUS "GNU detected include skip")

endif()
# detected phase &&
# include GNU compiler /bits header

add_subdirectory(./Brickjoon_Src)
# source directory add

MESSAGE(STATUS "done : root/")
# root finish