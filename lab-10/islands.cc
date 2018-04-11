#include <iostream>

int main() {

    // read number of trials
    int trials;
    std::cin >> trials;

    // loop over all trials
    int myid;
    int sequence[12];
    for (int i = 0; i < trials; i++) {
        // read input
        std::cin >> myid;
        for (int j = 0; j < 12; j++) {
            std::cin >> sequence[j];
        }
        
        // do your work here
        // TODO
        
        // print output
        // TODO
    }

}
