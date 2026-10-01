cmake_minimum_required(VERSION 3.22)
project(ex1_n__hadar19 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(ex1_n__hadar19
        cipher.c
        cipher.h
        main.c
        tests.c
        tests.h)
