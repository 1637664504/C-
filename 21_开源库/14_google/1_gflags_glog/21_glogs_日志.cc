#include<iostream>
#include <glog/logging.h>

int main(int argc, char* argv[]) {
    // 初始化 glog
    google::InitGoogleLogging(argv[0]);

    // 设置日志级别
    FLAGS_logtostderr = 1;
    FLAGS_minloglevel = google::GLOG_INFO;

    // 使用 glog
    LOG(INFO) << "这是一个 INFO 级别的日志";
    LOG(WARNING) << "这是一个 WARNING 级别的日志";
    LOG(ERROR) << "这是一个 ERROR 级别的日志";
    LOG(FATAL) << "这是一个 FATAL 级别的日志";

    // 关闭 glog
    google::ShutdownGoogleLogging();

    return 0;
}