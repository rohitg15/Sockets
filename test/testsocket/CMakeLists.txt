file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(testsocket ${SRCS})

TARGET_LINK_LIBRARIES(testsocket
    libsocket
    libgtest
    libgmock
)

add_test(NAME testsocket
         COMMAND testsocket)
