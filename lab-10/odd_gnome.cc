#include <iostream>

int main(int argc, char** argv) {
    // read number of cases (groups)
    int num_groups;
    std::cin >> num_groups;
    
    // loop to process each case
    for (int i = 0; i < num_groups; i++) {
        
        // read number of gnomes
        int num_gnomes;
        std::cin >> num_gnomes;
        
        // read gnomes
        int* gnomes = new int[num_gnomes];
        for (int j = 0; j < num_gnomes; j++) {
            std::cin >> gnomes[j];
        }
        
        // do your work here 
        // TODO: process this case
        // ...
        
        // TODO print the result here
        
        // delete memory
        delete [] gnomes;
    }

    return 0;
}
