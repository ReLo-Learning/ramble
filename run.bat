@echo off

cmake -S . -B build
cmake --build build

build\Debug\ramble.exe .\demo\demo.rmbl