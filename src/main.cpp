#include <iostream>
#include "cpu.h"

int main()
{
    CPU cpu;

    std::cout << "Linux System Monitor\n";
    std::cout << "CPU Usage: "
              << cpu.getUsage()
              << "%\n";

    return 0;
}