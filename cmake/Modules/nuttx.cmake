# test
set(MAKE_THREADS 8)
set(NUTTX_PATH ${CMAKE_SOURCE_DIR}/src/nuttx)

find_program(MAKE make)
find_program(CP cp)
find_program(UNZIP unzip)
find_program(MV mv)
find_program(RM rm)

set(V 0)
if (${VERBOSE})
	set(V,"V=2")
endif()


macro(nuttx_export BOARD CONFIG)
	set(V 0)
	if (${VERBOSE})
		set(V 2)
	endif()
	set(NUTTX_MAKE_CMD V=2 CC=${CMAKE_C_COMPILER} ${MAKE})
	set(NUTTX_NAME nuttx-${BOARD}-${CONFIG})
	set(ZIP_FILE ${CMAKE_BINARY_DIR}/${NUTTX_NAME}.zip)
	add_custom_target(${NUTTX_NAME}-config ALL
		COMMAND ./configure.sh ${BOARD}/${CONFIG}
		WORKING_DIRECTORY ${NUTTX_PATH}/tools
		)
	add_custom_command(OUTPUT ${ZIP_FILE}
		COMMAND cd tools && ./configure.sh ${BOARD}/${CONFIG}
		COMMAND ${NUTTX_MAKE_CMD} clean
		COMMAND ${NUTTX_MAKE_CMD} export -j${MAKE_THREADS}
		COMMAND ${MV} nuttx-export.zip ${ZIP_FILE}
		DEPENDS ${NUTTX_NAME}-config
		WORKING_DIRECTORY ${NUTTX_PATH}
		)
	add_custom_target(OUTPUT ${NUTTX_NAME} ALL
		COMMAND ${UNZIP} ${ZIP_FILE}
		COMMAND ${MV} nuttx-export ${NUTTX_NAME}
		WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
		DEPENDS ${ZIP_FILE}
		)
	include_directories(
		${CMAKE_BINARY_DIR}/${NUTTX_EXPORT}/include)
	link_libraries(
		${CMAKE_BINARY_DIR}/nuttx-${BOARD}-${CONFIG}/libs/libnuttx.a)
endmacro()

