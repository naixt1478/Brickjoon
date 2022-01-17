cmake_minimum_required (VERSION 3.20)
# cmake req version

project (Brickjoon)
# cmake root project name

set(CMAKE_SOURCE_DIR /Brickjoon)
set(CMAKE_BUILD_DIR /build)
set(CMAKE_BUILD_TYPE DEBUG_CONFIGURATIONS)
set(CURRENT_SOURCE_DIR "Brickjoon")
option(ENABLE_COVERAGE "Enable coverage" OFF)

if(ENABLE_COVERAGE)
    add_compile_options(--coverage)
    add_link_options(--coverage)
endif()

message(STATUS "coverage status : "${ENABLE_COVERAGE})

message(STATUS "detected compiler : "${CMAKE_CXX_COMPILER_ID})

# set env phase
if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
	message(STATUS "MSVC detected include activate")
	include_directories("include/Mingw64/")

elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	message(STATUS "GNU detected include skip")

else()
	message(STATUS "not suppoted toolchain")

endif()
# detected phase &&
# include GNU compiler /bits header

add_subdirectory(./Brickjoon_Src)
# source directory add

MESSAGE(STATUS "done : root/")
# root finish