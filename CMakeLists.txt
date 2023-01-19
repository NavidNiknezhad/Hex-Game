cmake_minimum_required(VERSION 3.17)
project(HexGameBaseCode)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(HexGameBaseCode
        Board.h
        HexGame.h
        HumanPlayer.h
        Main.cpp
        Player.h)
