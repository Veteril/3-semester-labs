cmake_minimum_required(VERSION 3.19)
project(11)

set(CMAKE_CXX_STANDARD 14)

add_executable(11 main.cpp Architect.cpp Architect.h ArchitectualObject.cpp ArchitectualObject.h Coordinate.cpp Coordinate.h Flat.cpp Flat.h Floor.cpp Floor.h House.cpp House.h)