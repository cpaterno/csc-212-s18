#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <ctime>
#include <unordered_set>
#include <set>
#include <sstream>

void spellCheckHashTable(const std::string& filename, const std::unordered_set<std::string>& dict) {
	std::cout << "Processing " << filename << " with a hash table ... ";
	// TODO: open the file given by `filename` -- use `ifstream`
	// TODO: iterate the file using `getline`
	// TODO: for each line in the file, split the line into words using `istringstream`
	// TODO:     for each word in the line, write to the stdout if the word is not in `dict`
	std::cout << "ok!" << std::endl;
}

void spellCheckRedBlack(const std::string& filename, const std::set<std::string>& dict) {
	std::cout << "Processing " << filename << " with a red black tree ... ";
	// TODO: open the file given by `filename` -- use `ifstream`
	// TODO: iterate the file using `getline`
	// TODO: for each line in the file, split the line into words using `istringstream`
	// TODO:     for each word in the line, write to the stdout if the word is not in `dict`
	std::cout << "ok!" << std::endl;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// main function
//---------------------------------------------------------------------------
int main() {
	std::string token;
	std::ifstream dict_file("american-english");

	// create a set backed by a hashtable
	std::unordered_set<std::string> dict_ht;

	// create a set backed by a red black tree
	std::set<std::string> dict_rb;

	// this loop reads all lines from the dictionary
	unsigned int count = 0;
    while(std::getline(dict_file, token)) {
		// at every iteration `token` contains one word from the american-english file
		// TODO: insert token into the hash table
		// TODO: insert token into the redblack tree
		count += 1;
    }
    std::cout << count << " words read from the american-english dictionary" << std::endl;

	// performs spell checking using a hashtable
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	spellCheckHashTable("alice.txt", dict_ht);
	spellCheckHashTable("pride.txt", dict_ht);
	spellCheckHashTable("war.txt", dict_ht);
	std::chrono::steady_clock::time_point end= std::chrono::steady_clock::now();
	std::cout << "Time for Hash Tables = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;

	// performs spell checking using a red black tree
	begin = std::chrono::steady_clock::now();
	spellCheckRedBlack("alice.txt", dict_rb);
	spellCheckRedBlack("pride.txt", dict_rb);
	spellCheckRedBlack("war.txt", dict_rb);
	end = std::chrono::steady_clock::now();
	std::cout << "Time for Red-Black Trees = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;
}