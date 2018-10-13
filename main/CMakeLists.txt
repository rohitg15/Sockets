set(Main_SRCS
    main.cpp
)

add_executable(socket
    ${Main_SRCS}
)

# Specify here the libraries this program depends on
target_link_libraries(myApp
    libfoo
    libtls
    libsocket
)

install(TARGETS myApp DESTINATION bin)
