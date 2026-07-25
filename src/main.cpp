#include <iostream>
#include "network_layer/UdpServer.h"

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

    server.Shutdown();
    return 0;
}
