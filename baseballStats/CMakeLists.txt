cmake_minimum_required(VERSION 3.15)
project(baseball)

set(CMAKE_CXX_STANDARD 14)

add_executable(baseball
        main.cpp
        Player.h
        Skills.h
        Team.h
        Game.h
        Bases.h
        Bases.cpp
        Team.cpp
        Game.cpp
        IRandomize.h
        StdRandomize.cpp
        StdRandomize.h
        Types.h
        Player.cpp)