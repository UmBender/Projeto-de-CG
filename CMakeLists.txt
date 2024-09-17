# Versão do CMake
cmake_minimum_required(VERSION 3.10)

# Nome do Projeto
project(ProjetoCG1)

# Versão do CPP
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Procura a bibliotecas Glut e OpenGL
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

# Bibliotecas que serão incluidas
include_directories(${OPENGL_INCLUDE_DIR} ${GLUT_INCLUDE_DIR})

# Arquivos fontes
set(SOURCE_FILES src/main.cpp src/Flowers/Flower.cpp src/Flowers/Seeder.cpp 
src/Flowers/FlowerTypes/Sunflower.cpp src/Flowers/FlowerTypes/Daisy.cpp 
src/Flowers/FlowerTypes/Rose.cpp
)

# Define o diretório alvo do programa
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/target)

# Cria o executavel
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Linka a bibliotecas
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})

# Flags proprias para cada tipo de build

# Versão otimizada para release
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

# Versão para debug
set(CMAKE_CXX_FLAGS_DEBUG "-Og -g -DDEBUG -pedantic -Wall -Wextra -Wpedantic -Wshadow") 

# Flags adicionais para release
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} \
                -O3 -pedantic -pedantic-errors \
								-Wall -Werror -Wextra -Wpedantic -Wshadow \
								-Wvla -Wswitch-enum -Wpointer-arith \
								-Woverloaded-virtual -Wnull-dereference \
								-Wmissing-include-dirs -Wlogical-op  \
								-Wformat=2 -Wduplicated-cond \
								-Wduplicated-branches -Wcast-qual
")

# Sistema para configuração de tipo de build
# Este comando força o tipo de build para versão de depuração.
# Utilizar as flags  "-DCMAKE_BUILD_TYPE=Release" e "-DCMAKE_BUILD_TYPE=Debug"
# para selecionar a versão de compilção.
# set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose the type of build." FORCE)
