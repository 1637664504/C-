
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/shm.h>

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
    cycleQueue(int Size)
    {
        this->front = 0;
        this->rear = 0;
        this->size = Size;
        this->count = 0;
        // this->data = new T[size];
    }
    ~cycleQueue()
    {
        // delete this->data;
    }

    void map_data(void *mem_address)
    {
        this->data = (T *)mem_address;
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
            // throw bad_exception();
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

#define APP_SHM_KEY 7788
#define SHM_WRITE 0
// #define SHM_READONLY SHM_RDONLY

template <class T>
class shmCycleQueue: public cycleQueue<T>
{
private:
    int key_id;
    int shm_id;
    void *shm_address;
public:
    shmCycleQueue(int key,int number,int flags=SHM_RDONLY)
    :cycleQueue<T>(number)
    {
        int mem_size = sizeof(class cycleQueue<T>) + sizeof(T)*number;
        this->shm_id = shmget(key,mem_size,0644|IPC_CREAT);
        if(this->shm_id == -1)
        {
            perror("shmget 共享内存异常");
            throw "初始化共享内存异常";
        }
        this->shm_address = shmat(this->shm_id,NULL,flags);
        this->map_data((void *)(this->shm_address)+sizeof(class cycleQueue<T>));
    }

    ~shmCycleQueue()
    {
        shmdt(this->shm_address);
    }

};


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