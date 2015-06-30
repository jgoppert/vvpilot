add_library(common ${LIBTYPE}
	common.c
	)

link_libraries(common)

add_executable(test_common
	test_common.c
	)

add_test(test_common ${TEST_FLAGS} test_common)
