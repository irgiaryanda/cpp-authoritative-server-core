#include "UdpServer.h"
#include <cstdio>

bool UdpServer::Initialize(uint16_t port)
{
#ifdef _WIN32
    // WSA init
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
        return false;
#endif

    // Create socket
    m_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

#ifdef _WIN32
    if (m_socket == INVALID_SOCKET)
    {
        WSACleanup();
        return false;
    }
#else
    if (m_socket < 0)
        return false;
#endif

    // Bind address
    sockaddr_in addr{};
    addr.sin_family      = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port        = htons(port);

    if (bind(m_socket, reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) != 0)
    {
        Shutdown();
        return false;
    }

    // Non-blocking mode
#ifdef _WIN32
    u_long mode = 1;
    if (ioctlsocket(m_socket, FIONBIO, &mode) != 0)
    {
        Shutdown();
        return false;
    }
#else
    int flags = fcntl(m_socket, F_GETFL, 0);
    if (flags < 0 || fcntl(m_socket, F_SETFL, flags | O_NONBLOCK) < 0)
    {
        Shutdown();
        return false;
    }
#endif

    m_port = port;
    return true;
}

void UdpServer::Shutdown()
{
#ifdef _WIN32
    if (m_socket != INVALID_SOCKET)
    {
        closesocket(m_socket);
        m_socket = INVALID_SOCKET;
    }
    WSACleanup();
#else
    if (m_socket >= 0)
    {
        close(m_socket);
        m_socket = -1;
    }
#endif
}
