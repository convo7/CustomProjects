cmake_minimum_required(VERSION 3.10)
project(PhotoPressmark)

set(CMAKE_CXX_STANDARD 14)

add_executable(PhotoPressmark main.cpp actions.h actions.cpp)

find_package(Threads REQUIRED)
target_link_libraries(${CMAKE_PROJECT_NAME} Threads::Threads)