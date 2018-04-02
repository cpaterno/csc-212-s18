#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "quick_sort.h"
#include "linkedlist.h"
#include "DoublyLinkedList.h"
#include <iostream>

bool is_sorted(int* arr, int n) {
    for (int i=1; i<n; ++i) if (arr[i-1] > arr[i]) return false;
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

/** Quick sort performs: O(n^2), O(n^2), O(n^2), O(n log n)* on average.
 */

/** Linked lists:
 *
 *
 */
TEST_CASE("Linked List") {
    SECTION("Constructor") {
        LinkedList list;
        REQUIRE(list.getSize() == 0);
    }
    SECTION("append") {
        LinkedList list;
        for (int i=0; i<5; ++i) list.append(i);
        REQUIRE(list.getSize() == 5);
    }
    SECTION("prepend") {
        LinkedList list;
        for (int i=0; i<5; ++i) list.prepend(i);
        REQUIRE(list.getSize() == 5);
    }
    SECTION("removeFirst") {
        LinkedList list;
        for (int i=0; i<5; ++i) list.append(i);
        int test;
        for (int i=0; i<5; ++i) {
            test = list.removeFirst();
            REQUIRE(test == i);
        }
        REQUIRE(list.getSize() == 0);
    }
    SECTION("removeLast") {
        LinkedList list;
        for (int i=0; i<5; ++i) list.prepend(i);
        int test;
        for (int i=0; i<5; ++i) {
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
        for (int i=0; i<10; ++i) list.append(i);
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
        for (int i=0; i<10; ++i) list.append(i);
        bool test = list.find(0);
        REQUIRE(test);
        test = list.find(11);
        REQUIRE_FALSE(test);
    }
    SECTION("clear") {
        LinkedList list;
        for (int i=0; i<10; ++i) list.append(i);
        list.clear();
        REQUIRE(list.getSize() == 0);
        REQUIRE_THROWS(list.removeAt(2));
    }
    SECTION("reverse") {
        LinkedList list;
        for (int i=0; i<10; ++i) list.append(i);
        list.reverse();
        REQUIRE(list.removeFirst() == 9);
        REQUIRE(list.removeLast() == 0);
    }
}

/** Linked Lists - 2)
 * Function; SLL; SLL without Tail; DLL
 * int size(); O(1); O(1); O(1)
 * int at(); O(n); O(n); O(n)
 * int front(); O(1); O(1); O(1)
 * int back(); O(1); O(n); O(1)
 * bool empty(); O(1); O(1); O(1)
 * void clear(); O(n); O(n); O(n)
 * void set(); O(n); O(n); O(n)
 * void push_back(); O(1); O(n); O(1);
 * int pop_back(); O(n); O(n); O(1);
 * void insert(); O(n); O(n); O(n)
 * void erase(); O(n); O(n); O(n)
 * void reverse(); O(n); O(n); O(n)
 */

TEST_CASE("DLL") {
    SECTION("prepend") {
        DoublyLinkedList list;
        for (int i=0; i<10; ++i) list.prepend(i);
        REQUIRE(list.getSize() == 10);
    }
    SECTION("append") {
        DoublyLinkedList list;
        for (int i=0; i<10; ++i) list.append(i);
        REQUIRE(list.getSize() == 10);
    }
    SECTION("removeFirst") {
        DoublyLinkedList list;
        for (int i=0; i<10; ++i) list.append(i);
        for (int i=0; i<10; ++i)
            REQUIRE(list.removeFirst() == i);
        REQUIRE_THROWS(list.removeFirst());
        REQUIRE(list.getSize() == 0);
    }
    SECTION("removeLast") {
        DoublyLinkedList list;
        for (int i=0; i<10; ++i) list.prepend(i);
        for (int i=0; i<10; ++i)
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
        for (int i=0; i<10; i++) list.append(i);
        REQUIRE(list.removeAt(5) == 5);
        REQUIRE(list.removeAt(5) == 6);
        REQUIRE(list.removeAt(5) == 7);
    }
}

/** Lomuto uses the last element, the method presented here uses the first.
 * This, in fact, does not matter. There are no partition schemes in Quick Sort that can change the worst-case
 * classification of O(n^2). Though some can help minimize the times this happens, you cannot guarantee better
 * performance by simply changing the partition scheme. Moreover, most partition schemes that minimize worst-case
 * runtimes, require more operations to be done upfront while selecting the pivot. Thus, making them less desirable
 * than their simpler siblings.
 */