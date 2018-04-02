cmake_minimum_required(VERSION 3.10)
project(quicksort)

set(CMAKE_CXX_STANDARD 11)

add_executable(quicksort main.cpp quick_sort.cpp quick_sort.h catch.hpp linkedlist.cpp linkedlist.h DoublyLinkedList.cpp DoublyLinkedList.h)