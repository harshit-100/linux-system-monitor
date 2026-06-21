#include <iostream>

#include "cpu.h"
#include "memory.h"
#include "process.h"

int main()
{
    CPU cpu;
    Memory memory;
    Process process;

    std::cout << "Linux System Monitor\n\n";

    std::cout << "CPU Usage: "
              << cpu.getUsage()
              << "%\n";

    std::cout << "Memory Usage: "
              << memory.getUsage()
              << "%\n";

    std::cout << "Processes: "
          << process.getProcessCount()
          << '\n';

    return 0;
}