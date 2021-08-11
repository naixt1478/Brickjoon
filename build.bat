@echo off
gcc --version
g++ --version
ninja --version
cmake --version
mkdir build
mkdir bin
cmake -S . -B .\build -G "Ninja"
cd build
ninja -v
move *.exe ..
cd ..
move .\*.exe .\bin
