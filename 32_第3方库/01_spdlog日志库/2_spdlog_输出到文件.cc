#include <stdint.h>
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

    spdlog::info("start spdlog");
    SPDLOG_LOGGER_INFO(logger, "Support for floats {}", "hello world");

    spdlog::drop("logger");
    spdlog::shutdown();
    
    return 0;
}

/*
cat logs/spdlog_test.log

20231219-10:46:11.588 [spdlog_test:info] <:> start spdlog
20231219-10:46:11.588 [spdlog_test:info] <2_spdlog_输出到文件.cc:19> Support for floats hello world
 */