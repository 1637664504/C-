#include <sys/shm.h>
#include "cycleQueue.h"

#ifndef __shmCycleQueue_h__
#define __shmCycleQueue_h__

#define APP_SHM_KEY 7788
#define SHM_WRITE 0
#define SHM_READONLY SHM_RDONLY

template <class T>
class shmCycleQueue: public cycleQueue<T>
{
private:
    int key_id;
    int shm_id;
    void *shm_address;

public:
    shmCycleQueue(int key,int number,int flags=SHM_RDONLY);
    ~shmCycleQueue();
};

#endif