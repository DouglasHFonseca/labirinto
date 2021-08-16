cmake_minimum_required(VERSION 3.19)
project(Prova2 C)

set(CMAKE_C_STANDARD 99)

include_directories(headers src)

add_executable(Prova2 main.c headers/mouseStack.h src/Pilha.c src/mouseMovement.c headers/mouseMovement.h src/userStack.c headers/userStack.h src/interfaceGrafica.c headers/interfaceGrafica.h)