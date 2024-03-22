#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_INFO

#include "spdlog/spdlog.h"
#include "spdlog/sinks/rotating_file_sink.h"
using namespace std;

void writeLog(int n) {
    int i = 0;
    // for (; i < n; ++i)
    {
        // 获取logger后输出日志
        auto myLogger = spdlog::get("baseLogger");
        myLogger->info("{}: Hello, {}!", i + 1, "World");
        myLogger->info("Welcome to spdlog!");
        myLogger->error("Some error message with arg: {}", 1);

        // 带文件名与行号的日志输出
        SPDLOG_LOGGER_INFO(myLogger, "Support for floats {:03.2f}", 1.23456);
        SPDLOG_LOGGER_WARN(myLogger, "Easy padding in numbers like {:08d}", 12);

        // 输出到默认日志中
        spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
        spdlog::error("Some error message with arg: {}", 1);
        spdlog::warn("Easy padding in numbers like {:08d}", 12);
        spdlog::info("Support for floats {:03.2f}", 1.23456);
    }
}

void testSPDLog() {
    string tag = "baseLogger";
    // 设定日志最大100k，且最多保留10个
    auto myLogger = spdlog::rotating_logger_mt(tag, "logs/basic.log", 1024 * 100, 10);
    spdlog::set_default_logger(myLogger);
    myLogger->set_pattern("[%Y-%m-%d %H:%M:%S.%e][%l](%@): %v"); // 非通过宏输出的日志%@输出为空
    myLogger->set_level(spdlog::level::info);

    myLogger->info("Hello, {}!", "World");

    writeLog(10);

    spdlog::drop(tag);
    spdlog::shutdown();
}

int main(void)
{
    testSPDLog();

    return 0;
}