#include <stdint.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
using namespace std;

void log_pattern_test()
{
    spdlog::info("Welcome to spdlog!");
    spdlog::set_pattern("[%c] [pid %P][thread id: %t] [%l] %v");
    spdlog::info("Welcome to spdlog!");
}

int main(void)
{
    log_pattern_test();

    return 0;
}
