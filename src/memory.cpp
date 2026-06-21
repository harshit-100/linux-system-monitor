#include "memory.h"

#include <fstream>
#include <string>

double Memory::getUsage()
{
    std::ifstream file("/proc/meminfo");

    std::string key;
    long value;

    long total = 0;
    long available = 0;

    while (file >> key >> value)
    {
        if (key == "MemTotal:")
        {
            total = value;
        }
        else if (key == "MemAvailable:")
        {
            available = value;
        }

        file.ignore(1000, '\n');
    }

    return 100.0 *
           (total - available) /
           total;
}