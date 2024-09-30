cmake_minimum_required(VERSION 3.29)
project(jogo_da_velha C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(jogo_da_velha
    jogo_da_velha.c
    tabuleiro.h
    verificador_jogo.h)
