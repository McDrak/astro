cmake_minimum_required(VERSION 3.28)
project(astro)

set(CMAKE_CXX_STANDARD 20)

add_executable(astro sandbox/main.cpp
        src/Astro.cpp
        src/Astro.h)
