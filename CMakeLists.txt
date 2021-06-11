cmake_minimum_required(VERSION 3.15)
project(RedBlackDictionary)

set(CMAKE_CXX_STANDARD 14)

add_executable(RedBlackDictionary main.cpp RedBlackNode.cpp RedBlackNode.h RedBlackTree.cpp RedBlackTree.h)