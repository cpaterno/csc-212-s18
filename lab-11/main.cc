#include <iostream>
#include <string>
#include "bst.h"
#include <assert.h>

void removePunctuation(std::string*);
void toLower(std::string*);


int main() {


	//Test removePunctuation
	std::string str("abc123.");
	removePunctuation(&str);
	assert(str == "abc123");
	str = "abc123;";
	removePunctuation(&str);
	assert(str == "abc123");
	str = "abc123\"";
	removePunctuation(&str);
	assert(str == "abc123");
	str = "abc123'";
	removePunctuation(&str);
	assert(str == "abc123");
	str = "abc'123";
	removePunctuation(&str);
	assert(str == "abc123");
	str = "abc123!";
	removePunctuation(&str);
	assert(str == "abc123");

	//Test toLower
	str = "ABCDEFG";
	toLower(&str);
	assert(str == "abcdefg");
	str = "AbCdEfG";
	toLower(&str);
	assert(str == "abcdefg");
	str = "ABC123";
	toLower(&str);
	assert(str == "abc123");

	//Test Both BSTree functions insert and BST_Height
	BSTree bstTest;
	assert(bstTest.BST_Height() == 0);
	//Insert Testing
	bstTest.insert("abc");
	bstTest.insert("xyz");
	bstTest.insert("abd");
	bstTest.insert("wxy");
	bstTest.insert("aam");
	bstTest.insert("aaz");
	bstTest.insert("aaa");
	//Remove Testing
	bstTest.remove("abc");
	bstTest.remove("xyz");
	bstTest.remove("abe");
	assert(bstTest.BST_Height() == 1);


	BSTree bst;
	std::string token;
    while(std::cin >> token)
    {
    	// TODO
    	// Implement removePunctuation()
    	// If the string is empty, continue
    	// Implement toLower()
    	// Insert to your tree
    }


}


void removePunctuation(std::string*) {
	//TODO
}
void toLower(std::string*) {
	//TODO
}
