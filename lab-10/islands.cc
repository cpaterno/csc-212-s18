#include <iostream>

int count_islands(int* sequence, int start, int end) {
    /*
     *  Your solution here
     */
}

int main() {

    int trials;
    std::cin >> trials;

    int* island_counts = new int[trials];
    for (int i = 0; i < trials; i++) {
        int* sequence = new int[12];
        std::cin >> sequence[0];
        for (int j = 0; j < 12; j++) {
            std::cin >> sequence[j];
        }
        island_counts[i] = count_islands(sequence, 0, 11);
        delete [] sequence;
    }

    for (int i = 0; i < trials; i++) {
        std::cout << i+1 << ' ' << island_counts[i] << std::endl;
    }
    delete [] island_counts;

}