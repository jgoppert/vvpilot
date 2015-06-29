cmake_minimum_required(VERSION 2.8)

project(vvpilot C)

set(CBMC_FLAGS ${CBMC_FLAGS}
	#--all-properties
	)

# build setup
set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-Wall -Werror")
enable_testing()
include_directories(src)

# cbmc handling
if (CBMC)
	set(LIBTYPE "SHARED")
	set(TEST_FLAGS ${CBMC} ${CBMC_FLAGS}) 
else()
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
add_subdirectory(src/vvp/commander)
