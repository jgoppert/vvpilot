cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}
	"${CMAKE_SOURCE_DIR}/cmake/Modules/")
include(join)

project(vvpilot C)

set(CBMC_FLAGS ${CBMC_FLAGS}
	# for now, don't unwind more than 2, takes a long
	# time and debugging
	--unwind 3
	--no-unwinding-assertions
	)

# build setup
set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS}
	-std=c99
	-Wall
	-Wextra
	-Werror
	-Wfatal-errors
	)
join("${CMAKE_C_FLAGS}" " " CMAKE_C_FLAGS)
message(STATUS "CFLAGS: ${CMAKE_C_FLAGS}")

enable_testing()
include_directories(src)

# cbmc handling
message(STATUS "CBMC: ${CBMC}")
if (CBMC)
	message(STATUS "model checking build")
	set(LIBTYPE "SHARED")
	set(TEST_FLAGS ${CBMC} ${CBMC_FLAGS}) 
else()
	message(STATUS "standard build")
	set(LIBTYPE "STATIC")
	set(TEST_FLAGS)
	add_subdirectory(src/vvp/cbmc)
	link_libraries(cbmc_stub)
endif()

# formatting
file(GLOB_RECURSE SRC_FILES "src/vvp/*.c")
file(GLOB_RECURSE HDR_FILES "src/vvp/*.h")
message(STATUS ${SRC_FILES})
add_custom_target(format
	astyle ${SRC_FILES} ${HDR_FILES}
	)

# main library

add_subdirectory(src/vvp/common)
add_subdirectory(src/vvp/modules/commander)
add_subdirectory(src/vvp/modules/mavlink_transceiver)
