#pragma once
#include <cstdint>

#ifdef _WIN32
    #include <winsock2.h>
    #include <ws2tcpip.h>
#else
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <unistd.h>
    #include <fcntl.h>
#endif

// UDP server
class UdpServer
{
public:
    bool Initialize(uint16_t port); // Bind socket
    void Shutdown();                // Cleanup

private:
#ifdef _WIN32
    SOCKET m_socket = INVALID_SOCKET; // Win socket
#else
    int m_socket = -1;                // Unix socket
#endif
    uint16_t m_port = 0;              // Bound port
};
