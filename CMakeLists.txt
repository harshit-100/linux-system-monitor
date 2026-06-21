cmake_minimum_required(VERSION 3.10)

project(LinuxSystemMonitor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(
    system_monitor
    src/main.cpp
    src/cpu.cpp
    src/memory.cpp
)