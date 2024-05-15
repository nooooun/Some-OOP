cmake_minimum_required(VERSION 3.28)
project(git_conteiner)

set(CMAKE_CXX_STANDARD 17)

add_executable(git_conteiner main.cpp
        Vector.h
        Shape.h
        VolumeShape.h
        Square.h
        Cube.h
        Circle.h
        Sphere.h
        Traingle.h
        Wedge.h)
