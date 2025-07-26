cmake_minimum_required(VERSION 3.31)
project(Simple_ECS)

set(CMAKE_CXX_STANDARD 23)

# Build as a shared library (dynamic)
add_library(Simple_ECS SHARED
        include/SimpleECS.cpp
        include/Types.h
        include/EntityManager.h
        include/ComponentArray.h
        include/ComponentManager.h
        include/System.h
        include/SystemManager.h
)

target_include_directories(Simple_ECS PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
