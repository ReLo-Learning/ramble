@echo off

cmake -S . -B build
cmake --build build

build\Debug\ramble.exe C:\Users\lreut\Desktop\Programs\Ramble\examples\functions.rmbl