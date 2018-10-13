#include "socket.h"
#include "testbasesocket.h"



BaseSocketTest::BaseSocketTest()
{
    m_invalidSocketId = -1;
};

BaseSocketTest::~BaseSocketTest()
{

};

void BaseSocketTest::SetUp()
{

};

void BaseSocketTest::TearDown()
{

};

TEST_F(BaseSocketTest, InvalidSocketIdThrows)
{
    EXPECT_THROW(ChildSocketTest childSocket{-1}, std::runtime_error);
}

TEST_F(BaseSocketTest, ValidSocketReturnsSocketId)
{
    int socketId = 0;
    ChildSocketTest childSocket0(socketId);
    ASSERT_EQ(childSocket0.GetSocketId(), socketId);

    socketId = 10;
    ChildSocketTest childSocket10(socketId);
    ASSERT_EQ(childSocket10.GetSocketId(), socketId);
}

TEST_F(BaseSocketTest, CheckSocketResetOnClose)
{
    int socketId = 0;
    ChildSocketTest childSocket(socketId);
    ASSERT_EQ(childSocket.GetSocketId(), socketId);

    childSocket.CloseSocket();
    ASSERT_EQ(childSocket.GetSocketId(), m_invalidSocketId);
}

TEST_F(BaseSocketTest, CloseInvalidSocketThrows)
{
    int socketId = 0;
    ChildSocketTest childSocket(socketId);
    childSocket.CloseSocket();
    ASSERT_EQ(childSocket.GetSocketId(), m_invalidSocketId);
    ASSERT_THROW(childSocket.CloseSocket(), std::runtime_error);
}