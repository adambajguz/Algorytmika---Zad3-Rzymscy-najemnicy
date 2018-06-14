cmake_minimum_required(VERSION 3.8)
project(Ps3_Zad3)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c)
add_executable(Ps3_Zad3 ${SOURCE_FILES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s -O3 -fexpensive-optimizations -static")