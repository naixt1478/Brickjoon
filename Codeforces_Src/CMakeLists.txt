#project name
project(codeforces_source)

# get source lists
file(GLOB_RECURSE CODEFORCES_LIST CONFIGURE_DEPENDS "*/*.cpp")

# source -> bin
foreach(SOURCE_PATH ${CODEFORCES_LIST})
	# get solve source number(name)
	get_filename_component(EXECUTABLE_NAME ${SOURCE_PATH} NAME_WE)
	# get last dir name
	get_filename_component(FULL_DIR_NAME ${SOURCE_PATH} PATH)
	get_filename_component(LAST2_DIR_PATH ${FULL_DIR_NAME} PATH)
	get_filename_component(LAST_DIR_NAME ${FULL_DIR_NAME} NAME)
	get_filename_component(LAST2_DIR_NAME ${LAST2_DIR_PATH} NAME)
	# last dir + number(name) 
	add_executable (${LAST2_DIR_NAME}_${LAST_DIR_NAME}-${EXECUTABLE_NAME} ${SOURCE_PATH})
	# log
	MESSAGE(STATUS "add : " ${LAST2_DIR_NAME}_${LAST_DIR_NAME}-${EXECUTABLE_NAME})
	# done
	endforeach(SOURCE_PATH ${CODEFORCES_LIST})
# return finish
MESSAGE(STATUS "done : src2/")