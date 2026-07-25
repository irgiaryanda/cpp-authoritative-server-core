add_library(server_core STATIC
    network_layer/UdpServer.cpp
    gameplay_logic/MovementValidator.cpp
)

add_executable(server_main main.cpp)

target_link_libraries(server_main PRIVATE server_core)
