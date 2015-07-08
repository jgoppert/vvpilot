#set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS}
	#-Wpedantic
	#-pedantic-errors
	#)
join("${CMAKE_C_FLAGS}" " " CMAKE_C_FLAGS)

add_library(commander
	StateManual.c
	StateAuto.c
	StateGuided.c
	Commander.c
	)

link_libraries(commander)

add_executable(test_commander
	test_commander.c
	)

add_test(test_commander ${TEST_FLAGS} test_commander)
