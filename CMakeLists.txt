cmake_minimum_required(VERSION 3.27)
project(rbdb)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(
    src
)

add_executable(rbdb
    src/main.c 
)
