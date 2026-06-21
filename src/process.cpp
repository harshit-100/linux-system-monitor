#include "process.h"

#include <filesystem>

int Process::getProcessCount()
{
    int count = 0;

    for (const auto& entry :
         std::filesystem::directory_iterator("/proc"))
    {
        if (entry.is_directory())
        {
            std::string name =
                entry.path().filename().string();

            bool isPid = !name.empty();

            for (char c : name)
            {
                if (!std::isdigit(c))
                {
                    isPid = false;
                    break;
                }
            }

            if (isPid)
            {
                count++;
            }
        }
    }

    return count;
}