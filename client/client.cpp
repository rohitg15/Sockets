#include "socket.h"
#include <iostream>

int main(int argc, char *argv[])
{

    std::string hostname = "127.0.0.1";
    std::vector<uint8_t> msg = {0x0A, 0x0B, 0x0C, 0x0D};
    std::vector<uint8_t> readMsg;
    readMsg.resize(1024);
    int port = 8080, numBytes = 0;
    sockets::ClientSocket clientSocket(hostname, port);
    clientSocket.PutMessage(msg);
    clientSocket.GetMessage(readMsg, numBytes);
    std::cout << "Server :";
    for (int i = 0; i < numBytes; ++i)
    {
        std::cout << (int)(readMsg[i]) << " ";
    }
    std::cout << std::endl;
    clientSocket.CloseSocket();
    return 0;
}
