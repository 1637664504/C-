#include <iostream>
#include <string>
#include <zmqpp/zmqpp.hpp>
#include <unistd.h>
using namespace std;
int main()
{
    zmqpp::context context;
    const string addr_port = "tcp://*:5555";
    zmqpp::socket_type type = zmqpp::socket_type::publish;
    zmqpp::socket socket = zmqpp::socket(context, type);
    socket.bind(addr_port);
    int i = 0;
    while (i < 100)
    {
        zmqpp::message message;
        message << "test[" + to_string(i++) + "]";
        socket.send(message);
        sleep(1);
    }
    return 0;
}
