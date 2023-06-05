#include <stdint.h>
#include <stdio.h>
// #include "cycleQueue.h"
#include "shmCycleQueue.h"

template <class T>
shmCycleQueue<T>::shmCycleQueue(int key, int number, int flags)
    : cycleQueue<T>(number)
{
    int mem_size = sizeof(class cycleQueue<T>) + sizeof(T) * number;
    this->shm_id = shmget(key, mem_size, 0644 | IPC_CREAT);
    if (this->shm_id == -1)
    {
        perror("shmget 共享内存异常");
        throw "初始化共享内存异常";
    }
    this->shm_address = shmat(this->shm_id, NULL, flags);
    this->map_data((void *)(this->shm_address) + sizeof(class cycleQueue<T>));
}

template <class T>
shmCycleQueue<T>::~shmCycleQueue()
{
    shmdt(this->shm_address);
}

template class shmCycleQueue<int>;
