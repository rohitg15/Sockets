#ifndef _STATE_MACHINE_H_
#define _STATE_MACHINE_H_

#include "socket.h"
#include <memory>

class StateMachine
{
public:
    StateMachine(
        int port,
        int qLen = 10
    ); 


    void ListenForever();

private:
     std::unique_ptr<sockets::ServerSocket> m_pServerSock;
    
};


#endif      //  _STATE_MACHINE_H_