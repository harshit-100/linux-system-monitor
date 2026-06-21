#include <chrono>
#include <iostream>
#include <thread>

#include "cpu.h"
#include "memory.h"
#include "process.h"

int main()
{
    CPU cpu;
    Memory memory;
    Process process;

    while (true)
    {
        system("clear");

        std::cout << "Linux System Monitor\n\n";

        std::cout << "CPU Usage    : "
                  << cpu.getUsage()
                  << "%\n";

        std::cout << "Memory Usage : "
                  << memory.getUsage()
                  << "%\n";

        std::cout << "Processes    : "
                  << process.getProcessCount()
                  << "\n";

        std::this_thread::sleep_for(
            std::chrono::seconds(1));
    }

    return 0;
}