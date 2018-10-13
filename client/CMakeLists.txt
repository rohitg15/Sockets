set(Main_SRCS
    client.cpp
)

add_executable(client
    ${Main_SRCS}
)

# Specify here the libraries this program depends on
target_link_libraries(client
    libsocket
)

install(TARGETS client DESTINATION bin)
