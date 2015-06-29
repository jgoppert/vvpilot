add_library(commander ${LIBTYPE}
	State.c
	StateManual.c
	StateAuto.c
	Commander.c
	)

link_libraries(commander)

add_executable(test_commander
	test_commander.c
	)

add_test(test_commander ${CBMC} test_commander)
