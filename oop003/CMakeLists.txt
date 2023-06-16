cmake_minimum_required(VERSION 3.22)
project(oop003)

set(CMAKE_CXX_STANDARD 20)

add_executable(castle main.cpp Room.cpp Room.h Castle.cpp Castle.h MonsterRoom.cpp MonsterRoom.h PrincessRoom.cpp PrincessRoom.h)
