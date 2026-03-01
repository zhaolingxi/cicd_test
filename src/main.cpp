#include <fmt/core.h>

int main() {
    fmt::print("Hello from CMake + FetchContent + CPack! fmt version: {}.{}.{}\n",
               FMT_VERSION / 10000, (FMT_VERSION / 100) % 100, FMT_VERSION % 100);
    return 0;
}