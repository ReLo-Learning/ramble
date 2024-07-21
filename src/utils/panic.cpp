#include "panic.hpp"

void panic(const std::string message)
{
    std::cerr << message << std::endl;
    exit(1);
}