#include "spdlog/spdlog.h"

int main(void)
{
    spdlog::info("info msg");
    spdlog::set_level(spdlog::level::debug);
    spdlog::debug("int {0:d} {1:4f}", 12, 3.14);
    return 0;
}