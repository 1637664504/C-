//  Hello World client
#include <zmq.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "zmq_common.h"

int main(void)
{
    printf("Connecting to hello world server…\n");
    void *context = zmq_ctx_new();
    void *requester = zmq_socket(context, ZMQ_REQ);
    zmq_connect(requester, "tcp://localhost:5555");

    int request_nbr;
    struct zmq_data data = {0};
    for (request_nbr = 0; request_nbr != 10; request_nbr++)
    {
        data.idx++;
        printf("Sending Hello %d…\n", request_nbr);
        zmq_send(requester, &data, sizeof(data), 0);
        zmq_recv(requester,  &data, sizeof(data), 0);
        printf("Received World %d idx=%u\n", request_nbr,data.count);
    }
    zmq_close(requester);
    zmq_ctx_destroy(context);
    return 0;
}
