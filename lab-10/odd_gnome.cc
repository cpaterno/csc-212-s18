#include <iostream>

int* odd_gnome(int num_groups, int* gs_in_each, int** groups) {
    /*
     *  Your solution here
     */
}

int main(int argc, char** argv) {

    int num_groups;
    std::cin >> num_groups;
    int** groups = new int*[num_groups];
    int* gs_in_each = new int[num_groups];
    for (int i = 0; i < num_groups; i++) {
        int num_gnomes;
        std::cin >> num_gnomes;
        gs_in_each[i] = num_gnomes;
        int* gnomes = new int[num_gnomes];
        for (int j = 0; j < num_gnomes; j++) {
            std::cin >> gnomes[j];
        }
        groups[i] = gnomes;
    }

    int* result = odd_gnome(num_groups, gs_in_each, groups);

    for (int i = 0; i < num_groups; i++) {
        std::cout << result[i] << std::endl;
    }

    return 0;
}