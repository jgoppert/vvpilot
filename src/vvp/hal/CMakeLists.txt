set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS}
	-Wpedantic
	)
join("${CMAKE_C_FLAGS}" " " CMAKE_C_FLAGS)

message(STATUS "CFLAGS: ${CMAKE_C_FLAGS}")


if (NOT CBMC)
	add_subdirectory(posix)
endif()
