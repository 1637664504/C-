#include <iostream>
#include "spdlog/spdlog.h"

int main() {

    std::cout << "hello world" << std::endl;

    spdlog::info("Welcome to spdlog!");
    spdlog::error("Some error message with arg: {}", 1);

    spdlog::warn("Easy padding in numbers like {:08d}", 12);
    spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
    spdlog::info("Support for floats {:03.2f}", 1.23456);
    spdlog::info("Positional args are {1} {0}..", "too", "supported");
    spdlog::info("{:<30}", "left aligned");

    return 0;
}

/*
hello world
[2023-12-19 14:40:14.203] [info] Welcome to spdlog!
[2023-12-19 14:40:14.203] [error] Some error message with arg: 1
[2023-12-19 14:40:14.203] [warning] Easy padding in numbers like 00000012
[2023-12-19 14:40:14.203] [critical] Support for int: 42;  hex: 2a;  oct: 52; bin: 101010
[2023-12-19 14:40:14.203] [info] Support for floats 1.23
[2023-12-19 14:40:14.203] [info] Positional args are supported too..
[2023-12-19 14:40:14.203] [info] left aligned

 */