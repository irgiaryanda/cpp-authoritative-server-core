# C++ Authoritative Server Core

[![CMake Build and Test](https://github.com/irgiaryanda/cpp-authoritative-server-core/actions/workflows/cmake.yml/badge.svg)](https://github.com/irgiaryanda/cpp-authoritative-server-core/actions)

A production-grade, headless authoritative multiplayer server core written in C++20. This project serves as a foundational architecture demonstrating robust networking, memory safety, and strict anti-cheat validation tailored for real-time action games.

## 🧠 Design Philosophy

As a Senior Backend Networking Engineer, this architecture prioritizes three core tenets:
1.  **Deterministic Execution:** Locking the server to a strict 30 Ticks Per Second (TPS) prevents physics drift and CPU monopolization.
2.  **Zero-Overhead Serialization:** JSON and string parsing are strictly prohibited in the network layer. Data is serialized using packed bitwise C++ structs (`#pragma pack`) to minimize packet payload and parsing latency.
3.  **Strict Decoupling:** The networking layer (UDP sockets) is completely isolated from the gameplay logic (movement validation). This allows for pure algorithmic unit testing without opening mock sockets.

## 🏗️ Project Architecture

```text
cpp-authoritative-server-core/
├── .github/workflows/       # CI/CD Pipeline for Automated Linux Builds
├── src/
│   ├── main.cpp             # Entry Point & Deterministic 30 TPS Game Loop
│   ├── network_layer/       # Native Non-blocking UDP Sockets (Winsock/POSIX)
│   └── gameplay_logic/      # Server-Authoritative Math & State Validation
├── tests/                   # Google Test (GTest) Automated Scenarios
└── CMakeLists.txt           # Cross-Platform Build Configuration
```

## ✨ Key Features

**Raw UDP Networking:** Implements non-blocking `recvfrom` socket draining. Cross-platform ready (POSIX/Winsock).

**Server-Authoritative Anti-Cheat:** Calculates exact Euclidean distance (`std::hypot`) between client ticks. Automatically rejects speedhacks, teleportation exploits, and invalid client actions, preparing the state for rubberbanding.

**Memory Safety:** Adheres to modern C++ semantics. Zero raw pointers (`*`) for state management, eliminating memory leaks and dangling references.

**Automated Testing:** CI/CD pipeline integrated with GitHub Actions. Automatically compiles and executes Google Test suites on an Ubuntu runner to ensure mathematical correctness of the anti-cheat logic.

## 🚀 Build & Run Instructions

This project requires a C++20 compatible compiler and CMake (3.14+).

### 1. Clone & Configure
```bash
git clone https://github.com/irgiaryanda/cpp-authoritative-server-core.git
cd cpp-authoritative-server-core
cmake -B build -DCMAKE_BUILD_TYPE=Release
```

### 2. Build the Server
```bash
cmake --build build --config Release
```

### 3. Run Automated Anti-Cheat Tests
```bash
cd build
ctest -C Release --output-on-failure
```

## 🔮 Future Roadmap (Scale & Optimization)

While this core establishes the fundamental authoritative loop, a production-ready game server would expand upon this with:

- **Client Prediction & Server Reconciliation:** Handling input buffers and applying rollback physics.
- **Delta State Compression:** Transmitting only changed entity properties to minimize bandwidth.
- **Lag Compensation:** Implementing historical state rewinding for hit registration.
