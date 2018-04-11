#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "sort/quick_sort.h"
#include "lists/linkedlist.h"
#include "lists/DoublyLinkedList.h"
#include "containers/queue.h"
#include "containers/stack.h"

bool is_sorted(int *arr, int n) {
    for (int i = 1; i < n; ++i) if (arr[i - 1] > arr[i]) return false;
    return true;
}

TEST_CASE("Quick Sort") {
    int sorted[] = {1, 2, 3, 4, 5};
    quicksort(sorted, 5);
    REQUIRE(is_sorted(sorted, 5));

    int reverse[] = {5, 4, 3, 2, 1};
    quicksort(reverse, 5);
    REQUIRE(is_sorted(reverse, 5));

    int same[] = {5, 5, 5, 5, 5, 5};
    quicksort(same, 6);
    REQUIRE(is_sorted(same, 6));

    int random[] = {5, 2, 6, 8, 2, 7};
    quicksort(random, 6);
    REQUIRE(is_sorted(random, 6));
}

TEST_CASE("Linked List") {
    SECTION("Constructor") {
        LinkedList list;
        REQUIRE(list.getSize() == 0);
    }
    SECTION("append") {
        LinkedList list;
        for (int i = 0; i < 5; ++i) list.append(i);
        REQUIRE(list.getSize() == 5);
    }
    SECTION("prepend") {
        LinkedList list;
        for (int i = 0; i < 5; ++i) list.prepend(i);
        REQUIRE(list.getSize() == 5);
    }
    SECTION("removeFirst") {
        LinkedList list;
        for (int i = 0; i < 5; ++i) list.append(i);
        int test;
        for (int i = 0; i < 5; ++i) {
            test = list.removeFirst();
            REQUIRE(test == i);
        }
        REQUIRE(list.getSize() == 0);
    }
    SECTION("removeLast") {
        LinkedList list;
        for (int i = 0; i < 5; ++i) list.prepend(i);
        int test;
        for (int i = 0; i < 5; ++i) {
            test = list.removeLast();
            REQUIRE(test == i);
        }
        REQUIRE(list.getSize() == 0);
    }
    SECTION("insertAt") {
        LinkedList list;
        list.insertAt(0, 5);
        list.insertAt(1, 4);
        list.insertAt(0, 6);
        list.insertAt(2, 10);
        REQUIRE(list.getSize() == 4);
    }
    SECTION("removeAt") {
        LinkedList list;
        for (int i = 0; i < 10; ++i) list.append(i);
        int test;
        test = list.removeAt(5);
        REQUIRE(test == 6);
        test = list.removeAt(5);
        REQUIRE(test == 7);
        test = list.removeAt(5);
        REQUIRE(test == 8);

        REQUIRE_THROWS(list.removeAt(100));
        REQUIRE_THROWS(list.removeAt(-10));
    }
    SECTION("find") {
        LinkedList list;
        for (int i = 0; i < 10; ++i) list.append(i);
        bool test = list.find(0);
        REQUIRE(test);
        test = list.find(11);
        REQUIRE_FALSE(test);
    }
    SECTION("clear") {
        LinkedList list;
        for (int i = 0; i < 10; ++i) list.append(i);
        list.clear();
        REQUIRE(list.getSize() == 0);
        REQUIRE_THROWS(list.removeAt(2));
    }
    SECTION("reverse") {
        LinkedList list;
        for (int i = 0; i < 10; ++i) list.append(i);
        list.reverse();
        REQUIRE(list.removeFirst() == 9);
        REQUIRE(list.removeLast() == 0);
    }
}

TEST_CASE("DLL") {
    SECTION("prepend") {
        DoublyLinkedList list;
        for (int i = 0; i < 10; ++i) list.prepend(i);
        REQUIRE(list.getSize() == 10);
    }
    SECTION("append") {
        DoublyLinkedList list;
        for (int i = 0; i < 10; ++i) list.append(i);
        REQUIRE(list.getSize() == 10);
    }
    SECTION("removeFirst") {
        DoublyLinkedList list;
        for (int i = 0; i < 10; ++i) list.append(i);
        for (int i = 0; i < 10; ++i)
            REQUIRE(list.removeFirst() == i);
        REQUIRE_THROWS(list.removeFirst());
        REQUIRE(list.getSize() == 0);
    }
    SECTION("removeLast") {
        DoublyLinkedList list;
        for (int i = 0; i < 10; ++i) list.prepend(i);
        for (int i = 0; i < 10; ++i)
            REQUIRE(list.removeLast() == i);
        REQUIRE_THROWS(list.removeLast());
        REQUIRE(list.getSize() == 0);
    }
    SECTION("insert_at") {
        DoublyLinkedList list;
        list.insertAt(0, 1);
        list.insertAt(1, 2);
        list.insertAt(0, 3);
        REQUIRE_THROWS(list.insertAt(10, 100));
        REQUIRE(list.getSize() == 3);
    }
    SECTION("remove_at") {
        DoublyLinkedList list;
        for (int i = 0; i < 10; i++) list.append(i);
        REQUIRE(list.removeAt(5) == 5);
        REQUIRE(list.removeAt(5) == 6);
        REQUIRE(list.removeAt(5) == 7);
    }
}

TEST_CASE("Queue") {
    Queue q;
    for (int i = 0; i < 10; ++i) {
        q.push(i);
    }
    REQUIRE(q.peek() == 0);
    for (int i = 0; i < 10; ++i) {
        REQUIRE(q.pop() == i);
    }
    REQUIRE_THROWS(q.pop());
}

TEST_CASE("Stack") {
    Stack s;
    for (int i = 0; i < 10; ++i)
        s.push(i);
    REQUIRE(s.peek() == 9);
    for (int i = 9; i >= 0; --i)
        REQUIRE(s.pop() == i);
    REQUIRE_THROWS(s.pop());
}