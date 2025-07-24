cmake_minimum_required(VERSION 3.31)
project(Simple_ECS)

set(CMAKE_CXX_STANDARD 23)

add_library(Simple_ECS SHARED src/SimpleECS.cpp
        include/Types.h
        src/EntityManager.cpp
        include/EntityManager.h
        src/ComponentArray.cpp
        include/ComponentArray.h)
