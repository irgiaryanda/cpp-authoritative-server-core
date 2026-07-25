include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(server_tests validation_tests.cpp)

target_link_libraries(server_tests PRIVATE gtest_main server_core)

include(GoogleTest)
gtest_discover_tests(server_tests)
