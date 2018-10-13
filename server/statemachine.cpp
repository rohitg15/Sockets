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
        m_pServerSock->BlockingWrite(writeMsg);
        m_pServerSock->BlockingRead(readMsg);
        std::cout << "Client : ";
        for(auto const& val : readMsg)
        {
            std::cout << std::hex << val << " ";
        }
        std::cout << std::endl;
    }
}