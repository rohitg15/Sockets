#ifndef _TEST_SOCKET_H_
#define _TEST_SOCKET_H_

#include "gtest/gtest.h"


class ChildSocketTest : public sockets::BaseSocket
{
public:
    ChildSocketTest(
        int socketId
    ): BaseSocket(socketId)
    {};

    int GetSocketId() const
    {
        return BaseSocket::GetSocketId();
    }
};

class BaseSocketTest : public ::testing::Test
{
protected:

    BaseSocketTest();

    virtual ~BaseSocketTest();

    virtual void SetUp();

    virtual void TearDown();
public:
    int m_invalidSocketId;
};



#endif  //  _TEST_SOCKET_H_