#include "cpu.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

void CPU::printStats()
{
    std::ifstream file("/proc/stat");

    if (!file.is_open())
    {
        std::cerr << "Failed to open /proc/stat\n";
        return;
    }

    std::string line;
    std::getline(file, line);

    std::stringstream ss(line);

    std::string cpu;

    long user;
    long nice;
    long system;
    long idle;

    ss >> cpu >> user >> nice >> system >> idle;

    std::cout << "\nCPU Statistics\n";
    std::cout << "User   : " << user << '\n';
    std::cout << "Nice   : " << nice << '\n';
    std::cout << "System : " << system << '\n';
    std::cout << "Idle   : " << idle << '\n';
}