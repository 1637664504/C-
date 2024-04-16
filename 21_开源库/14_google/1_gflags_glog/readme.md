安装
sudo apt install libgoogle-glog-dev


## gflags使用

#define DEFINE_bool(name, val, txt)

#define DEFINE_int32(name, val, txt)

#define DEFINE_uint32(name,val, txt) 

#define DEFINE_int64(name, val, txt)

#define DEFINE_uint64(name,val, txt) 

#define DEFINE_double(name, val, txt)


## glog 使用
设置日志输出目录 与 文件
```c
    //设置日志输出目录
    FLAGS_log_dir = "./logs";
    // google::SetLogDestination(google::GLOG_INFO, "./logs/info.");
    // google::SetLogDestination(google::GLOG_WARNING, "./logs/warning.");
    // google::SetLogDestination(google::GLOG_ERROR, "./logs/error.");
    // google::SetLogDestination(google::GLOG_FATAL, "./logs/fatal.");

    // 设置日志文件大小为10MB
    FLAGS_max_log_size = 10 * 1024;  // 10MB
```

- FLAGS_colorlogtostderr = true; 设置记录到标准输出的颜色消息 
