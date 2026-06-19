#include <iostream>
#include "cpu.h"

int main()
{
    std::cout << "Linux System Monitor\n";

    CPU cpu;
    cpu.printStats();

    return 0;
}