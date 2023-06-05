#include <stdbool.h>

#ifndef __cycleQueue__h
#define __cycleQueue__h

template <class T>
class cycleQueue
{
private:
    int size;
    int front;
    int rear;
    int count;
    T *data;

public:
    cycleQueue(int Size);
    ~cycleQueue();

    void map_data(void *mem_address);
    bool is_empty();
    bool is_full();
    void push(T ele, bool force = false);
    void force_push(T ele);
    T pop();

    int *get_data();
};

#endif