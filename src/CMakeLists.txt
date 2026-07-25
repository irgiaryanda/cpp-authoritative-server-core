add_library(server_core STATIC
    network_layer/UdpServer.cpp
    gameplay_logic/MovementValidator.cpp
)

# Winsock link
if(WIN32)
    target_link_libraries(server_core PUBLIC ws2_32)
endif()

add_executable(server_main main.cpp)

target_link_libraries(server_main PRIVATE server_core)
