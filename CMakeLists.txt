cmake_minimum_required(VERSION 3.4)

project(
    RambleCompiler
    VERSION 0.1
    DESCRIPTION "The greatest programming language of all time"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)

set(LLVM_DIR "D:/LLVM/libcmake")

find_package(LLVM REQUIRED CONFIG)

# SET(CMAKE_BUILD_TYPE "Debug")
# SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -Wall")
# SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

add_subdirectory(src)

add_executable(ramble ${CMAKE_SOURCE_DIR}/app/compiler.cpp)

llvm_map_components_to_libnames(llvmLib support core irreader)

target_link_libraries(
    ramble PUBLIC ErrorLib LexerLib HIRLib ParserLib ${llvmLib}
)

