#include <iostream>

int* mancala(int count, int* boxes_filled) {
    /*
     *  Your solution here
     */
}

int main() {

    int num_trials;
    std::cin >> num_trials;

    int* trials = new int[num_trials];
    for (int i = 0; i < num_trials; i++) {
        std::cin >> trials[i];
        std::cin >> trials[i];
    }

    int** results = new int*[num_trials];
    int* results_sizes = new int[num_trials];
    for (int i = 0; i < num_trials; i++) {
        results[i] = mancala(trials[i], results_sizes+i);
    }

    for (int i = 0; i < num_trials; i++) {
        std::cout << i + 1 << ' ' << results_sizes[i] << std::endl;
        for (int j = 0; j < results_sizes[i]; j++) {
            std::cout << results[i][j];
            if (j % 10 == 9 || j == results_sizes[i]) {
                std::cout << std::endl;
            } else {
                std::cout << ' ';
            }
        }
    }

    return 0;
}