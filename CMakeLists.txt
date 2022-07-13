cmake_minimum_required(VERSION 3.22)
project(chess C)

set(CMAKE_C_STANDARD 11)

add_executable(chess
        main.c chess.c chess.h)

add_executable(test_chess
        test.c chess.c chess.h)
