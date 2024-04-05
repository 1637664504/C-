#include "shmCycleQueue.hpp"
int main(void)
{
    // cycleQueue<int> q(5);
    shmCycleQueue<int> q(APP_SHM_KEY,5,SHM_WRITE);
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