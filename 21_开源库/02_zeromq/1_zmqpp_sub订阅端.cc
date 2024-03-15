#include <iostream>
#include <string>
#include <zmqpp/zmqpp.hpp>
using namespace std;
int main(int argc, char *argv[])
{
    zmqpp::context context;
    const string addr_port = "tcp://localhost:5555";
    zmqpp::socket_type type = zmqpp::socket_type::subscribe;
    zmqpp::socket socket = zmqpp::socket(context, type);
    socket.set(zmqpp::socket_option::subscribe, "");
    socket.connect(addr_port);
    while (1)
    {
        zmqpp::message message;
        socket.receive(message);
        std::cout << "recv data: " << message.get(0) << std::endl;
    }
    return 0;
}
