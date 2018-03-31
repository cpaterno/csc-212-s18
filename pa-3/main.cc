#include "cdll.h"
#include <fstream>
#include <sstream>
#include <iostream>

void read_file(const char *fname, CDLL *list) {
    std::ifstream myfile(fname);
    if (myfile) {
        std::string line;
        std::string tweet_id, tweet_time, tweet_text;
        // for each line in file
        while (getline(myfile,line)) {
            // splits the line by the delimiter '|'
            std::istringstream mystream(line);
            std::getline(mystream, tweet_id, '|');
            std::getline(mystream, tweet_time, '|');
            std::getline(mystream, tweet_text, '|');
            // -------------------------------------------
            // TODO - insert tweet into your CDLL
            // -------------------------------------------
        }
        myfile.close();
    }
}

int main(int argc, char *argv[]) {
    // creates an empty linked list
    CDLL list;
    // reads the contents of input file and insert tweets into list
    read_file(argv[1], &list);
    // main loop: waits for user interaction
    std::string command, word;
    while (true) {
        // prints the `current` tweet
        list.print_current();
        // reads entire line from user
        std::getline(std::cin, command);
        // creates a tokenizer to iterate over words
        std::stringstream tokens(command);
        // gets the first word from `tokens`
        tokens >> word;
        if (word.compare("n")) {
            // TODO: move `current` to next
        }
        if (word.compare("p")) {
            // TODO: move `current` to previous
        }
        if (word.compare("f")) {
            // TODO: move `current` to first
        }
        if (word.compare("l")) {
            // TODO: move `current` to last
        }
        if (std::all_of(word.begin(), word.end(), ::isdigit)) {
            int skip = std::stoi(word);
            // TODO: move `current` to `skip` positions ahead (circularly)
        }
        if (word.compare("s")) {
            tokens >> word;
            // TODO: move `current` to the next occurrence of `word`
        }
        if (word.compare("q")) {
            break;
        }
    }
}
