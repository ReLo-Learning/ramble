add_executable(ramble_tests tests.cpp)

target_link_libraries(ramble_tests RambleCompiler)

add_test(NAME RambleTests COMMAND ramble_tests)