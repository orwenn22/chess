cmake_minimum_required(VERSION 3.26)
project(chess C)

set(CMAKE_C_STANDARD 11)
add_subdirectory(raylib)
file(COPY res DESTINATION .)

add_executable(chess src/main.c
        src/Board.h
        src/Board.c)
target_link_libraries(chess PRIVATE raylib)
