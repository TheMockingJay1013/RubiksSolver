cmake_minimum_required(VERSION 3.27)
project(RubiksSolver)

set(CMAKE_CXX_STANDARD 17)

add_executable(RubiksSolver main.cpp
        RubiksCube.cpp
        RubiksCube.h
        RubiksCube3d.cpp
        dfs.h
        bfs.h
        IDDFS.h)
