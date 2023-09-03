cmake_minimum_required(VERSION 3.4)

project(
    Ramble
    VERSION 0.1
    DESCRIPTION "The greatest programming language of all time"
    LANGUAGES CXX
)

add_subdirectory(src)

add_executable(ramblec ${CMAKE_SOURCE_DIR}/app/compiler.cpp)

target_link_libraries(
    ramblec PUBLIC ErrorLib LexerLib
)

