cmake_minimum_required(VERSION 3.10)
project(SudokuCounter)

set(CMAKE_CXX_STANDARD 14)

add_executable(SudokuCounter main.cpp Sudoku.h Sudoku.cpp)