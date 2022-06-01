#project name
project(brickjoon_source)

# get source lists
file(GLOB_RECURSE BRICKJOON_LIST CONFIGURE_DEPENDS "*.cpp" "*.c")

# source -> bin
foreach(SOURCE_PATH ${BRICKJOON_LIST})
	# get solve source number(name)
	get_filename_component(EXECUTABLE_NAME ${SOURCE_PATH} NAME_WE)
	# get last dir name
	get_filename_component(FULL_DIR_NAME ${SOURCE_PATH} PATH)
	get_filename_component(LAST_DIR_NAME ${FULL_DIR_NAME} NAME)
	# last dir + number(name) 
	add_executable (${LAST_DIR_NAME}-${EXECUTABLE_NAME} ${SOURCE_PATH})
	# log
	MESSAGE(STATUS "add : " ${LAST_DIR_NAME}_${EXECUTABLE_NAME})
	# done
endforeach(SOURCE_PATH ${BRICKJOON_LIST})
# return finish
MESSAGE(STATUS "done : src/")