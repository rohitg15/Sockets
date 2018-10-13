cmake_minimum_required(VERSION 2.8)
set (CMAKE_CXX_STANDARD 14)

project(sockets)

enable_testing()

# add_subdirectory(main)
add_subdirectory(server)
add_subdirectory(client)
# add_subdirectory(test)
add_subdirectory(libsocket)
