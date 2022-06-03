@echo off

set BUILD_ROOT=_build

cmake -G Ninja -DCMAKE_CXX_COMPILER=clang++ -S . -B %BUILD_ROOT%
cmake --build %BUILD_ROOT%
