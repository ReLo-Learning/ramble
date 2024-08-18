cmake_minimum_required(VERSION 3.4)

project(
    RambleCompiler
    VERSION 0.1
    DESCRIPTION "The greatest programming language of all time"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src)

add_executable(ramble ${CMAKE_SOURCE_DIR}/app/compiler.cpp)

target_link_libraries(
    ramble PUBLIC ErrorLib LexerLib ASTLib ParserLib Utils Types Codegen
)

