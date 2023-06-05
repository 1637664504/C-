
#include <stdint.h>
#include <stdio.h>
#include "cycleQueue.h"

template <class T>
cycleQueue<T>::cycleQueue(int Size)
{
    this->front = 0;
    this->rear = 0;
    this->size = Size;
    this->count = 0;
    // this->data = new T[size];
}

template <class T>
cycleQueue<T>::~cycleQueue()
{
    // delete this->data;
}

template <class T>
void cycleQueue<T>::map_data(void *mem_address)
{
    this->data = (T *)mem_address;
}

template <class T>
bool cycleQueue<T>::is_empty()
{
    return this->count == 0;
}

template <class T>
bool cycleQueue<T>::is_full()
{
    return this->count == this->size;
}

template <class T>
void cycleQueue<T>::push(T ele, bool force)
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

template <class T>
void cycleQueue<T>::force_push(T ele)
{
    if (this->is_full())
    {
        this->pop();
    }
    data[rear] = ele;
    rear = (rear + 1) % size;
    count++;
}

template <class T>
T cycleQueue<T>::pop()
{
    if (this->is_empty())
    {
        printf("empty\n");
        return 0;
        // throw bad_exception();
    }
    T tmp = data[front];
    data[front] = 0;
    front = (front + 1) % size;
    count--;

    return tmp;
}

template <class T>
int *cycleQueue<T>::get_data()
{
    return this->data;
}

template class cycleQueue<int>;