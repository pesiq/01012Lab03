cmake_minimum_required(VERSION 3.16)
project(Lab03)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab03 main.cpp binaryTree.h dynamicArray.h binaryHeap.h exceptions.h)
add_executable(tests tests.cpp binaryTree.h dynamicArray.h binaryHeap.h exceptions.h)