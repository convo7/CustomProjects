cmake_minimum_required(VERSION 3.15)
project(baseball)

set(CMAKE_CXX_STANDARD 14)

add_executable(baseball main.cpp Player.h Skills.h Team.h Game.h Base.h Player.cpp Base.cpp Team.cpp Game.cpp)