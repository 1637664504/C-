#include <iostream>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
using namespace std;

// 开启使用数组,方便gdb查看
#define EASY_GDB_DEBUG 0
#define QUEUE_ARRAY_SIZE 5

template <class T>
class cycleQueue
{
private:
    int size;
    int front;
    int rear;
    int count;
#if EASY_GDB_DEBUG
    T data[QUEUE_ARRAY_SIZE];
#else
    T *data;
#endif

public:
    cycleQueue(int Size)
    {
        this->front = 0;
        this->rear = 0;
        this->size = Size;
        this->count = 0;
#ifndef EASY_GDB_DEBUG
        this->data = new T[size];
#endif
    }
    ~cycleQueue()
    {
#ifndef EASY_GDB_DEBUG
        delete this->data;
#endif
    }

    bool is_empty()
    {
        return this->count == 0;
    }

    bool is_full()
    {
        return this->count == this->size;
    }

    void push(T ele, bool force = false)
    {
        if (this->is_full())
        {
            if (force)
            {
                this->pop();
            }
            else
            {
                printf("full\n");
                return;
                // throw bad_exception();
            }
        }
        data[rear] = ele;
        rear = (rear + 1) % size;
        count++;
    }

    void force_push(T ele)
    {
        if (this->is_full())
        {
            this->pop();
        }
        data[rear] = ele;
        rear = (rear + 1) % size;
        count++;
    }

    T pop()
    {
        if (this->is_empty())
        {
            printf("empty\n");
            return 0;
            throw bad_exception();
        }
        T tmp = data[front];
        data[front] = 0;
        front = (front + 1) % size;
        count--;

        return tmp;
    }

    int *get_data()
    {
        return this->data;
    }
};

int main(void)
{
    cycleQueue<int> q(5);
    int *data = q.get_data();
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    // q.force_push(11);
    // q.force_push(12);
    q.push(11,true);
    q.push(12,true);

    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.push(7);
    q.push(8);
    q.pop();
    q.push(9);
    q.push(10);

    return 0;
}