#include "linkedlist.h"

#include <iostream>
#include <assert.h>

/*
 * No need to change main.cc
 *         Go away.
 */

void run_tests(LinkedList* ll)
{
	

	std::cout << "Test 1" << std::endl;
	for (int i = 0 ; i < 10 ; i++) {
		ll->append(i*10);
	}

	std::cout << "Test 2" << std::endl;
	for (int i = 0 ; i < 10 ; i++) {
		ll->prepend(i*10);
	}

	std::cout << "Test 3" << std::endl;
	ll->append(10);
	assert(ll->removeLast() == 10);
	ll->append(10);
	assert(ll->removeLast() == 10);

	std::cout << "Test 4" << std::endl;
	for (int i = 0 ; i < 20 ; i++) {
		ll->removeLast();
	}
	assert(ll->getSize() == 0);

	for (int i = 0 ; i < 10 ; i++) {
		ll->prepend(i*10);
	}
	assert(ll->getSize() == 10);
	assert(ll->removeLast() == 0);
	assert(ll->removeLast() == 10);
	assert(ll->removeLast() == 20);
	assert(ll->removeLast() == 30);
	assert(ll->removeLast() == 40);
	assert(ll->getSize() == 5);

	std::cout << "Test 5" << std::endl;
	for (int i = 0 ; i < 1000 ; i++) {
		ll->prepend(i);
	}
	assert(ll->getSize() == 1005);
	assert(ll->removeLast() == 50);
	assert(ll->removeLast() == 60);
	assert(ll->removeLast() == 70);
	assert(ll->removeLast() == 80);
	assert(ll->removeLast() == 90);
	assert(ll->removeLast() == 0);
	assert(ll->removeLast() == 1);
	assert(ll->getSize() == 998);

	std::cout << "Test 6" << std::endl;
	assert(! ll->getSize() == 0);

	std::cout << "Test 7" << std::endl;
	for (int i = 0 ; i < 900 ; i++) {
		ll->removeLast();
	}
	assert(ll->getSize() == 98);

	std::cout << "Test 8" << std::endl;
	ll->clear();
	assert(ll->getSize() == 0);

	std::cout << "Test 9" << std::endl;
	ll->append(10);
	assert(ll->removeLast() == 10);
	ll->append(10);
	assert(ll->removeLast() == 10);

	std::cout << "Test 10" << std::endl;
	assert(ll->getSize() == 0);

	std::cout << "Test 11" << std::endl;
	for (int i = 0 ; i < 1000 ; i++) {
		ll->append(i);
	}
	assert(ll->getSize() == 1000);
	assert(ll->removeLast() == 999);
	assert(ll->removeLast() == 998);
	assert(ll->removeLast() == 997);
	assert(ll->removeLast() == 996);
	assert(ll->removeLast() == 995);
	assert(ll->removeLast() == 994);
	assert(ll->removeLast() == 993);
	assert(ll->getSize() == 993);

	std::cout << "Test 12" << std::endl;
	for (int i = 0 ; i < 900 ; i++) {
		ll->removeLast();
	}
	assert(ll->getSize() == 93);

	std::cout << "Test 13" << std::endl;
	assert(! ll->getSize() == 0);
	ll->clear();
	assert(ll->getSize() == 0);

	std::cout << "Test 14" << std::endl;
	for (int i = 0 ; i < 10 ; i++) {
		ll->append(i*10);
	}
	ll->insertAt(5,10);
	assert(ll->getSize() == 11);
	ll->insertAt(0,0);
	assert(ll->getSize() == 12);
	ll->insertAt(11,12);
	assert(ll->getSize() == 13);

	std::cout << "Test 15" << std::endl;
	assert(ll->removeAt(11) == 12);
	assert(ll->removeAt(0) == 0);
	assert(ll->removeAt(5) == 10);

	std::cout << "Test 16" << std::endl;
	for (int i = 0 ; i < 10 ; i++) {
		assert(ll->find(i*10) == true);
	}

	std::cout << "Test 17" << std::endl;
	ll->clear();
	for (int i = 0; i < 1000000; i++) {
		if( i % 2 == 0) {
			ll->append(i);
		} else {
			ll->prepend(i);
		}
		assert(ll->getSize() == i+1);
	}

}

int main()
{

	std::cout << "=====TESTING SINGLY LINKED LIST=====" << std::endl;
	LinkedList ll;
	run_tests(&ll);
	std::cout << "All Done!" << std::endl;

	std::cout << "Completely Done!" << std::endl;

}
