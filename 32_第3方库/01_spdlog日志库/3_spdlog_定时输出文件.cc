#include <stdint.h>
#include <unistd.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/rotating_file_sink.h>
using namespace std;

int main(void)
{
    uint32_t file_size = 1024 * 1024 * 5;
    uint32_t file_num = 3;
    string tag = "spdlog_test";
    string log_path = "logs/" + tag + ".log";
    auto logger = spdlog::rotating_logger_mt(tag, log_path, file_size, file_num);
    spdlog::set_default_logger(logger);
    spdlog::set_level(spdlog::level::info);
    spdlog::set_pattern("%Y%m%d-%H:%M:%S.%e [%n:%l] <%g:%#> %v");
    spdlog::flush_every(chrono::seconds(3));

    spdlog::info("start spdlog");
    SPDLOG_LOGGER_INFO(logger, "Support for floats {}", "hello world");

    int count = 10;
    while (count--) {
        SPDLOG_LOGGER_INFO(logger, "count {:d}",count);
        sleep(1);
    }

    spdlog::drop("logger");
    spdlog::shutdown();
    
    return 0;
}

/*

 */