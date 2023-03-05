cmake_minimum_required(VERSION 3.12)
project(virtual_ecosystem)

set(CMAKE_CXX_STANDARD 20)

add_executable(virtual_ecosystem
    src/main.cpp
    src/position.cpp
    src/species_info.cpp
    src/random.cpp
    src/size.cpp
    src/settings.cpp
    src/organism.cpp
    src/map.cpp
)
