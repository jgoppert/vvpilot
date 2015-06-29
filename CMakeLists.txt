cmake_minimum_required(VERSION 2.8)

option(MC "enable model checking build" OFF)

set(LIBTYPE "STATIC")

if (MC)
	set(CMAKE_TOOLCHAIN_FILE 
		"${CMAKE_SOURCE_DIR}/cmake/goto-toolchain.cmake")
	set(LIBTYPE "SHARED")
endif()

project(vvpilot C)

enable_testing()

file(GLOB_RECURSE SRC_FILES "src/vvp/*.c")
file(GLOB_RECURSE HDR_FILES "src/vvp/*.h")

message(STATUS ${SRC_FILES})
add_custom_target(format
	astyle ${SRC_FILES} ${HDR_FILES}
	)

add_subdirectory(src/vvp/commander)
