set(CMAKE_SYSTEM_NAME Model-checking)

find_program(CBMC cbmc)

set(CMAKE_C_COMPILER goto-cc)
set(CMAKE_CXX_COMPILER goto-cc)
set(CMAKE_AR goto-cc)
set(CMAKE_CXX_CREATE_STATIC_LIBRARY "${CMAKE_CXX_CREATE_SHARED_LIBRARY}")
set(CMAKE_C_CREATE_STATIC_LIBRARY "${CMAKE_C_CREATE_SHARED_LIBRARY}")