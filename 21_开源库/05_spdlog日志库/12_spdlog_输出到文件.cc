#include <stdint.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
using namespace std;

void level_test()
{
    // 1. rotating_logger_mt 可以定制文件大小, 文件数量
    // 2. basic_logger_mt 基本实例
    auto logger = spdlog::basic_logger_mt("basic_logger", "logs/level-log.txt");

    logger->trace("spdlog level trace output");
    logger->debug("spdlog level debug output");
    logger->info("spdlog level info output");
    logger->warn("spdlog level warn output");
    logger->error("spdlog level error output");

    //在设置warn级别之后，warn以上的级别都不再输出。
    logger->set_level(spdlog::level::warn);

    logger->trace("spdlog level trace output");
    logger->debug("spdlog level debug output -2");
    logger->info("spdlog level info output -2 ");
    logger->warn("spdlog level warn output -2");
    logger->error("spdlog level error output -2");

    spdlog::drop("logger");
    spdlog::shutdown();
}

int main(void)
{
    level_test();

    return 0;
}

/*
tail -f logs/level-log.txt

[2023-12-19 14:53:41.046] [basic_logger] [info] spdlog level info output
[2023-12-19 14:53:41.046] [basic_logger] [warning] spdlog level warn output
[2023-12-19 14:53:41.046] [basic_logger] [error] spdlog level error output
[2023-12-19 14:53:41.046] [basic_logger] [warning] spdlog level warn output -2
[2023-12-19 14:53:41.046] [basic_logger] [error] spdlog level error output -2

 */