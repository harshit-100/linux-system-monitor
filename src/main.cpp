#include <iostream>

#include "cpu.h"
#include "memory.h"

int main()
{
    CPU cpu;
    Memory memory;

    std::cout << "Linux System Monitor\n\n";

    std::cout << "CPU Usage: "
              << cpu.getUsage()
              << "%\n";

    std::cout << "Memory Usage: "
              << memory.getUsage()
              << "%\n";

    return 0;
}