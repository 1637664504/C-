#include <string>
#include <iostream>
#include <unistd.h>
#include <zmq.hpp>
#include "message.pb.h"
using namespace std;

int main(void)
{
    zmq::context_t context(2);
    zmq::socket_t socket(context, zmq::socket_type::rep);
    const string addr_port = "tcp://*:5555";
    socket.bind(addr_port);

    while (true)
    {
        // 等待用户请求
        zmq::message_t request;
        socket.recv(request, zmq::recv_flags::none);

        std::string recv_str((char *)request.data(), request.size());
        UserMessage::Person ps;
        ps.ParseFromString(recv_str);

        std::cout << "服务端：" << ps.name() << " " << ps.id() << " " << ps.email() << " " << std::endl;

        // 做些处理
        sleep(1);

        // 应答world
        zmq::message_t reply(5);
        memcpy(reply.data(), "World", 5);
        socket.send(reply, zmq::send_flags::none);
        std::cout << "服务端：回复world" << std::endl;
    }
    return 0;
}
