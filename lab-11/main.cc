#include <iostream>
#include <string>
#include "bst.h"
#include <assert.h>

void removePunctuation(std::string*);
void toLower(std::string*);


int main() {

	//Test Both BSTree functions insert and treeHeight
	BSTree bstTest;
	assert(bstTest.treeHeight() == -1);

	//Insert Testing
	std::cout << "Testing insert..." << std::endl;
	std::string insert_tests[7] = {"abc", "xyz", "abd", "wxy", "aam", "aaz", "aaa"};
	for (int i = 0; i < 7; i++) {
		bstTest.insert(insert_tests[i]);
	}

	std::string insert_actual_preorder[] = {"abc", "aam", "aaa", "aaz", "xyz", "abd", "wxy"};
	std::string insert_test_preorder[7];
	bstTest.genPreorderArray(insert_test_preorder);
	for (int i = 0; i < 7; i++) {
		assert(insert_actual_preorder[i] == insert_test_preorder[i]);
	}

	std::string insert_actual_inorder[] = {"aaa", "aam", "aaz", "abc", "abd", "wxy", "xyz"};
	std::string insert_test_inorder[7];
	bstTest.genInorderArray(insert_test_inorder);
	for (int i = 0; i < 7; i++) {
		assert(insert_actual_inorder[i] == insert_test_inorder[i]);
	}

	//Remove Testing
	std::cout << "Testing remove..." << std::endl;
	std::string remove_tests[4] = {"wxy", "xyz", "aam", "abc"};
	for (int i = 0; i < 4; i++) {
		bstTest.remove(remove_tests[i]);
	}

	std::string remove_actual_preorder[] = {"abd", "aaz", "aaa"};
	std::string remove_test_preorder[3];
	bstTest.genPreorderArray(remove_test_preorder);
	for (int i = 0; i < 3; i++) {
		assert(remove_actual_preorder[i] == remove_test_preorder[i]);
	}

	std::string remove_actual_inorder[] = {"aaa", "aaz", "abd"};
	std::string remove_test_inorder[3];
	bstTest.genInorderArray(remove_test_inorder);
	for (int i = 0; i < 3; i++) {
		assert(remove_actual_inorder[i] == remove_test_inorder[i]);
	}

	// Duplicate/Search Testing
	std::cout << "Testing search and duplicates..." << std::endl;
	bstTest.insert("aaa");
	assert(bstTest.search("aaa") == 2);

	bstTest.remove("aaa");
	assert(bstTest.search("aaa") == 1);

	bstTest.remove("aaa");
	assert(bstTest.search("aaa") == 0);

	assert(bstTest.search("aaz") == 1);
	assert(bstTest.search("amd") == 0);

	std::cout << "All tree tests passed." << std::endl;


	//Test removePunctuation
	std::cout << "Testing removePunctuation..." << std::endl;
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
	std::cout << "Testing toLower..." << std::endl;
	str = "ABCDEFG";
	toLower(&str);
	assert(str == "abcdefg");
	str = "AbCdEfG";
	toLower(&str);
	assert(str == "abcdefg");
	str = "ABC123";
	toLower(&str);
	assert(str == "abc123");

	std::cout << "All string processing tests passed." << std::endl;

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
