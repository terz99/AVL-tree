cmake_minimum_required(VERSION 3.10)
project(AVL)

set(CMAKE_CXX_STANDARD 11)

add_executable(AVL testAVL.cpp AVLTree.cpp AVLTree.h)