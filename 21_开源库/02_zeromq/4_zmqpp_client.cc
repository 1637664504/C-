/// CS Pattern
#include <zmq.hpp>
#include <string.h>
#include <iostream>
#include "message.pb.h"

int main()
{
    zmq::context_t context(1);
    zmq::socket_t requester(context, zmq::socket_type::req);
    requester.connect("tcp://localhost:5555");

    for (int request_nbr = 0; request_nbr != 10; request_nbr++)
    {
        UserMessage::Person ps;
        ps.set_name("zeng");
        ps.set_id(2200);
        ps.set_email("zeng@qq.com");

        std::string ps_string;
        ps.SerializeToString(&ps_string);

        zmq::message_t request(ps_string.size());
        memcpy(request.data(), ps_string.c_str(), ps_string.size());

        requester.send(request, zmq::send_flags::none);
        std::cout << "客户端:请求数据，" << request.to_string() << std::endl;

        zmq::message_t reply;
        requester.recv(reply, zmq::recv_flags::none);
        std::cout << "客户端：接受返回数据" << std::endl;
    }
}
