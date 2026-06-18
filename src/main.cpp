#include <iostream>
#include "cpu.h"

int main()
{
    std::cout << "Linux System Monitor" << std::endl;

    CPU cpu;
    cpu.printInfo();

    return 0;
}