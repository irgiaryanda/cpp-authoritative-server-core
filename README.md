# C++ Authoritative Server Core

[![CMake Build and Test](https://github.com/irgiaryanda/cpp-authoritative-server-core/actions/workflows/cmake.yml/badge.svg)](https://github.com/irgiaryanda/cpp-authoritative-server-core/actions)

A production-grade, server-authoritative multiplayer backend core written in C++20. Designed to demonstrate robust network architecture, memory safety, and strict anti-cheat validation.

## Key Architecture & Features

* **Raw UDP Networking:** Non-blocking socket implementation using raw byte serialization. No JSON or string parsing overhead.
* **Deterministic Game Loop:** Fixed 30 Ticks Per Second (TPS) game loop using `<chrono>` to ensure physics determinism and prevent CPU monopolization.
* **Server-Authoritative Anti-Cheat:** Validates client movement using Euclidean distance (`std::hypot`) to prevent speedhacks and teleportation exploits. Invalid states trigger movement rejection.
* **Memory Safety:** Modern C++ practices ensuring zero memory leaks.
* **Automated Testing:** Core logic is fully isolated from the networking layer and verified using Google Test (GTest).

## Build Instructions
This project uses CMake and requires a C++20 compatible compiler.

```bash
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
```

## Running Unit Tests
```bash
cd build
ctest -C Release --output-on-failure
```
