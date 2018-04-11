cmake_minimum_required(VERSION 3.10)
project(wps-09-solutions)

set(CMAKE_CXX_STANDARD 11)

add_executable(wps-09-solutions main.cpp sort/quick_sort.cpp sort/quick_sort.h catch.hpp lists/linkedlist.cpp lists/linkedlist.h lists/DoublyLinkedList.cpp lists/DoublyLinkedList.h containers/stack.cpp containers/stack.h containers/queue.cpp containers/queue.h)