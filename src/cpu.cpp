#include "cpu.h"

#include <fstream>
#include <sstream>
#include <string>
#include <thread>
#include <chrono>

double CPU::getUsage()
{
    auto readStats = [](
        long& user,
        long& nice,
        long& system,
        long& idle,
        long& iowait,
        long& irq,
        long& softirq)
    {
        std::ifstream file("/proc/stat");

        std::string cpu;

        file >> cpu
             >> user
             >> nice
             >> system
             >> idle
             >> iowait
             >> irq
             >> softirq;
    };

    long user1, nice1, system1, idle1, iowait1, irq1, softirq1;
    long user2, nice2, system2, idle2, iowait2, irq2, softirq2;

    readStats(user1, nice1, system1, idle1,
              iowait1, irq1, softirq1);

    std::this_thread::sleep_for(
        std::chrono::seconds(1));

    readStats(user2, nice2, system2, idle2,
              iowait2, irq2, softirq2);

    long total1 =
        user1 + nice1 + system1 +
        idle1 + iowait1 + irq1 + softirq1;

    long total2 =
        user2 + nice2 + system2 +
        idle2 + iowait2 + irq2 + softirq2;

    long totalDelta = total2 - total1;
    long idleDelta = idle2 - idle1;

    return 100.0 *
           (totalDelta - idleDelta) /
           totalDelta;
}