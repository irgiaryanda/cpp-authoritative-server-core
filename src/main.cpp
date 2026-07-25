#include <iostream>
#include <chrono>
#include <thread>
#include <atomic>
#include "network_layer/UdpServer.h"
#include "gameplay_logic/MovementValidator.h"

// Tick rate
static constexpr int  k_ticksPerSecond = 30;
static constexpr auto k_tickDuration   = std::chrono::duration<double, std::milli>(1000.0 / k_ticksPerSecond);

std::atomic<bool> isRunning{true};

// Entry point
int main()
{
    UdpServer server;

    if (!server.Initialize(7777))
    {
        std::cerr << "Failed to initialize server\n";
        return 1;
    }

    std::cout << "Server running on port 7777\n";

    // Player setup
    PlayerState dummyPlayer;
    constexpr float k_maxSpeed = 5.0f;

    while (isRunning)
    {
        // Start time
        auto tickStart = std::chrono::steady_clock::now();

        // Drain buffer
        ClientInputPacket packet;
        while (server.Receive(packet))
        {
            // Validate movement
            if (!MovementValidator::ValidateAndApply(dummyPlayer, packet, k_maxSpeed))
            {
                std::cerr << "Speedhack detected, movement rejected\n";
            }
        }

        // Elapsed tick
        auto tickEnd = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(tickEnd - tickStart);

        // Sleep thread
        if (elapsed < k_tickDuration)
        {
            std::this_thread::sleep_for(k_tickDuration - elapsed);
        }
    }

    server.Shutdown();
    return 0;
}
