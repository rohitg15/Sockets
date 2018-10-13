#include "socket.h"
#include "statemachine.h"

int main(int argc, char *argv[])
{
    StateMachine server(8080);
    server.ListenForever();
    return 0;
}
