#include <iostream>
#include <thread>

class love
{
public:
    void shit(int ding);
};

void love::shit(int ding)
{
    std::cout << ding << " hahaha " << std::endl;
}

int main(int argc, const char* argv[])
{
    love abc;
    std::thread tt(&love::shit, &abc, 5);
    tt.join();

    return 0;
}
