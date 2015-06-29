add_library(hal_posix ${LIBTYPE}
	hal_posix.c
	serial.c
	)

add_executable(test_hal_posix
	test_hal_posix.c
	)
add_test(test_hal_posix test_hal_posix)
target_link_libraries(test_hal_posix
	hal_posix)
