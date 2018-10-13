set(Main_SRCS
    server.cpp
    statemachine.h
    statemachine.cpp
)

add_executable(server
    ${Main_SRCS}
)

# Specify here the libraries this program depends on
target_link_libraries(server
    libsocket
)

install(TARGETS server DESTINATION bin)
