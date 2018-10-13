file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(testtls ${SRCS})

TARGET_LINK_LIBRARIES(testtls
    libtls
    libgtest
    libgmock
)

add_test(NAME testtls
         COMMAND testtls)
