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

	//Test Both BSTree functions insert and treeHeight
	BSTree bstTest;
	assert(bstTest.treeHeight() == 0);
	//Insert Testing
	bstTest.insert("abc");
	bstTest.insert("xyz");
	bstTest.insert("abd");
	bstTest.insert("wxy");
	bstTest.insert("aam");
	bstTest.insert("aaz");
	bstTest.insert("aaa");

	std::string preOrder[] = {"abc", "aam", "aaa", "aaz", "xyz", "abd", "wxy"};
	//pre-order: abc, aam, aaa, aaz, xyz, abd, wxy
	bstTest.printPreorder();

	std::string inOrder[] = {"aaa", "aam", "aaz", "abc", "xyz", "abd", "wxy"};
	//in-order: aaa, aam, aaz, abc, xyz, abd, wxy
	bstTest.printInorder();

	std::string postOrder[] = {"aaa", "aaz", "aam", "wxy", "abd", "xyz", "abc"};
	//post-order: aaa, aaz, aam, wxy, abd, xyz, abc
	bstTest.printPostorder();

	//Remove Testing
	//leaf
	bstTest.remove("wxy");
	//parent with one child
	bstTest.remove("xyz");
	//parent with two children
	bstTest.remove("aam");
	//root node
	bstTest.remove("abc");
	assert(bstTest.treeHeight() == 1);


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
