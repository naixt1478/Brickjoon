cmake_minimum_required (VERSION 3.20)
# cmake req version

project (Brickjoon)
# cmake root project name

set(CMAKE_SOURCE_DIR /Brickjoon)
set(CMAKE_BUILD_DIR /build)
set(CMAKE_BUILD_TYPE Debug)
set(CURRENT_SOURCE_DIR "Brickjoon")

# REQ CXX 20 <=
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# option LINE
message(STATUS "coverage status : " ${ENABLE_COVERAGE})
message(STATUS "detected compiler : " ${CMAKE_CXX_COMPILER_ID})

# set env phase
if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
	message(STATUS "MSVC detected include activate")
	include_directories("include/Mingw64/")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++20")
	add_compile_options("/Zc:__cplusplus")
	# set(CMAKE_CXX_FLAGS_DEBUG "/ZI /Ob0 /Od /RTC1")

elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	message(STATUS "GNU detected include skip")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
	if(ENABLE_COVERAGE)
		add_compile_options(--coverage)
		add_link_options(--coverage)
	endif()

else()
	message(STATUS "not suppoted toolchain")

endif()
# detected phase &&
# include GNU compiler /bits header

add_subdirectory(./Brickjoon_Src)
add_subdirectory(./Codeforces_Src)
# source directory add

MESSAGE(STATUS "done : root/")
# root finish