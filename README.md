# Linux System Monitor

A real-time Linux system monitoring tool written in modern C++17, similar to `htop`. It reads directly from the Linux `/proc` filesystem to display live CPU usage, memory usage, and running processes.

## Goals

- Learn Linux internals
- Learn C++
- Learn CMake
- Learn system programming
- Build an htop-like monitor

## How It Works

The monitor runs in a continuous loop, refreshing the terminal every second with updated system stats.

### CPU Usage (`/proc/stat`)

Reads CPU time counters (user, nice, system, idle, iowait, irq, softirq) from `/proc/stat` at two points one second apart. It calculates the percentage of non-idle time over total time in that interval:

```
CPU% = 100 * (totalDelta - idleDelta) / totalDelta
```

### Memory Usage (`/proc/meminfo`)

Parses `/proc/meminfo` to extract `MemTotal` and `MemAvailable`, then computes used memory as a percentage:

```
Memory% = 100 * (MemTotal - MemAvailable) / MemTotal
```

### Process Listing (`/proc/[pid]/`)

Iterates over `/proc` directory entries. Directories with numeric names correspond to running processes. For each process:
- The PID is extracted from the directory name.
- The process name is read from `/proc/[pid]/comm`.

The top 10 processes are displayed in the terminal output.

## Project Structure

```
├── CMakeLists.txt
├── include/
│   ├── cpu.h          # CPU class declaration
│   ├── memory.h       # Memory class declaration
│   └── process.h      # Process class and ProcessInfo struct
├── src/
│   ├── main.cpp       # Main loop and display logic
│   ├── cpu.cpp        # CPU usage calculation
│   ├── memory.cpp     # Memory usage calculation
│   └── process.cpp    # Process enumeration
└── tests/
```

## Build & Run

```bash
mkdir build && cd build
cmake ..
make
./system_monitor
```

## Requirements

- Linux (relies on `/proc` filesystem)
- C++17 compiler
- CMake 3.10+

## Sample Output

```
=====================================
      Linux System Monitor
=====================================

CPU Usage    : 12.34%
Memory Usage : 56.78%
Processes    : 215

PID     NAME
-------------------------------------
1       systemd
2       kthreadd
3       rcu_gp
...
```
