#include "statemachine.h"
#include <iostream>

StateMachine::StateMachine(
    int port,
    int qLen
)
{
    m_pServerSock = std::make_unique<sockets::ServerSocket>(port, qLen);
}

void StateMachine::ListenForever()
{
    for (;;)
    {
        sockaddr_in clientAddr;
        socklen_t clientLen = 0;
        int clientFd = m_pServerSock->Accept((struct sockaddr *)&clientAddr, &clientLen);
        std::vector<uint8_t> writeMsg =  {0x00, 0x01, 0x02, 0x03};
        std::vector<uint8_t> readMsg;
        readMsg.resize(1024);
        m_pServerSock->BlockingWrite(clientFd, writeMsg);

        int numBytes = 0;
        m_pServerSock->BlockingRead(clientFd, readMsg, numBytes);
        std::cout << "Client : ";
        for(int i = 0; i < numBytes; ++i)
        {
            std::cout <<   (int)(readMsg[i]) << " ";
        }
        std::cout << std::endl;
    }
}