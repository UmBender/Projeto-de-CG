#!/bin/bash
# Versão para release
#cmake -DCMAKE_BUILD_TYPE=Release CMakeLists.txt 

# Versão para debug
cmake -DCMAKE_BUILD_TYPE=Debug CMakeLists.txt 

# Build o projeto
make

# Executa o programa
./target/ProjetoCG1

# Limpa arquivos gerados pelo cmake e make
rm -rf cmake_install.cmake CMakeFiles/ CMakeCache.txt Makefile target
