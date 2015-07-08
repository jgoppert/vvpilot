#set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS}
	#-Wpedantic
	#)
join("${CMAKE_C_FLAGS}" " " CMAKE_C_FLAGS)

add_library(cbmc_stub cbmc_stub.c)
