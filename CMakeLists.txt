cmake_minimum_required (VERSION 3.9)

project ("Brickjoon")
set(CMAKE_SOURCE_DIR /Brickjoon)
set(CMAKE_BUILD_DIR /build)

set(CURRENT_SOURCE_DIR "Brickjoon")
# Something BOJ Brickjoon
file(GLOB BRICKJOON_LIST ${CURRENT_SOURCE_DIR}/*.cpp)
foreach(SOURCE_PATH ${BRICKJOON_LIST})

get_filename_component(EXECUTABLE_NAME ${SOURCE_PATH} NAME_WE)

add_executable (baekjoon_${EXECUTABLE_NAME} ${SOURCE_PATH})

MESSAGE(STATUS "${SOURCE_PATH}")
endforeach(SOURCE_PATH ${BRICKJOON_LIST})

# Solved.ac Class 1
set(CURRENT_SOURCE_DIR "Brickjoon/Class_1_solvedac")

file(GLOB BRICKJOON_LIST ${CURRENT_SOURCE_DIR}/*.cpp)
foreach(SOURCE_PATH ${BRICKJOON_LIST})

get_filename_component(EXECUTABLE_NAME ${SOURCE_PATH} NAME_WE)

add_executable (Class-1_${EXECUTABLE_NAME} ${SOURCE_PATH})

MESSAGE(STATUS "${SOURCE_PATH}")
endforeach(SOURCE_PATH ${BRICKJOON_LIST})

# Solved.ac Class 2

set(CURRENT_SOURCE_DIR "Brickjoon/Class_2_solvedac")

file(GLOB BRICKJOON_LIST ${CURRENT_SOURCE_DIR}/*.cpp)
foreach(SOURCE_PATH ${BRICKJOON_LIST})

get_filename_component(EXECUTABLE_NAME ${SOURCE_PATH} NAME_WE)

add_executable (Class-2_${EXECUTABLE_NAME} ${SOURCE_PATH})

MESSAGE(STATUS "${SOURCE_PATH}")
endforeach(SOURCE_PATH ${BRICKJOON_LIST})
