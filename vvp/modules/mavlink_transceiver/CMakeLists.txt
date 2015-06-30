set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS}
	# can't have pedantic due to mavlink
	)
join("${CMAKE_C_FLAGS}" " " CMAKE_C_FLAGS)

add_library(mavlink_transceiver ${LIBTYPE}
	mavlink_transceiver.c
	)

include_directories(mavlink mavlink/common)

link_libraries(mavlink_transceiver)

if (NOT CBMC)
	link_libraries(m)
endif()

add_executable(test_mavlink_transceiver
	test_mavlink_transceiver.c
	)

add_test(test_mavlink_transceiver
	${TEST_FLAGS} test_mavlink_transceiver)
