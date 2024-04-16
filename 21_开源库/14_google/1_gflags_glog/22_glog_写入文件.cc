#include <glog/logging.h>

void SetupLogging(const std::string& logDir)
{
    // 设置日志输出目录
    FLAGS_log_dir = "./logs";
    // google::SetLogDestination(google::GLOG_INFO, "./logs/info.");
    // google::SetLogDestination(google::GLOG_WARNING, "./logs/warning.");
    // google::SetLogDestination(google::GLOG_ERROR, "./logs/error.");
    // google::SetLogDestination(google::GLOG_FATAL, "./logs/fatal.");

    // Set the minimum log level to be recorded. In this case, INFO and above.
    FLAGS_minloglevel = 0;  // 0: INFO, 1: WARNING, 2: ERROR, 3: FATAL

    // Optionally, you can also enable log file rotation and set the maximum log size:
    FLAGS_logfile_mode = 0644;  // Set file permissions (optional)
    FLAGS_logbufsecs = 0;  // Flush log buffer immediately (optional)

    // 设置日志级别
    FLAGS_stderrthreshold = google::INFO;

    // 设置日志文件大小为10MB
    FLAGS_max_log_size = 10 * 1024;  // 10MB

    // 禁用日志文件名中的机器名后缀
    FLAGS_alsologtostderr = true;
    FLAGS_logtostderr = false;

    // 设置记录到标准输出的颜色消息（如果终端支持）
    FLAGS_colorlogtostderr = true;

    // 自动移除旧日志 day （apt旧版本没有）
    // google::EnableLogCleaner(3);
}

void logCondition()
{
    for (int i = 0; i < 10; ++i)
    {
        // 条件日志
        LOG_IF(INFO, i > 5) << "Got lots of cookies" << i;
        LOG_EVERY_N(INFO, 10) << "Got the " << google::COUNTER << "th cookie";
    }
}

int main(int argc, char* argv[])
{
    // 设置日志目录
    std::string logDir = "./logs";

    // 初始化日志
    SetupLogging(logDir);

    // 初始化 Glog
    google::InitGoogleLogging(argv[0]);

    // 示例输出不同级别的日志
    LOG(INFO) << "This is an informational message.";
    LOG(WARNING) << "This is a warning message.";
    LOG(ERROR) << "This is an error message.";
    // LOG(FATAL) << "This is a fatal error message.";

    logCondition();

    google::ShutdownGoogleLogging();

    return 0;
}

/* 1. 不指定日志文件
22_glog_写入文件.out.DESKTOP-S8HP6V9.liuj.log.ERROR.20240416-224757.7276  22_glog_写入文件.out.DESKTOP-S8HP6V9.liuj.log.WARNING.20240416-224757.7276  22_glog_写入文件.out.INFO
22_glog_写入文件.out.DESKTOP-S8HP6V9.liuj.log.INFO.20240416-224757.7276   22_glog_写入文件.out.ERROR                                                  22_glog_写入文件.out.WARNING
 */

/* 2. 指定日志文件
UNKNOWN.ERROR  UNKNOWN.INFO  UNKNOWN.WARNING  error.20240416-224715.7144  info.20240416-224715.7144  warning.20240416-224715.7144
 */ 


