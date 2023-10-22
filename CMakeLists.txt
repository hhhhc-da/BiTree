cmake_minimum_required(VERSION 3.21)

# Compile Commands

# cmake -G "MinGW Makefiles" .
# mingw32-make

project(Tree)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(SRC_LIST  
    BiTree.cpp
    BiTree.hpp
)

add_executable(${PROJECT_NAME} ${SRC_LIST})

message(${PROJECT_NAME})
