#include <iostream>

int tarifa(int X, int N, int* P) {
    /*
     *  Your solution here
     */
}

int main(int argc, char** argv) {

    int X;
    std::cin >> X;
    int N;
    std::cin >> N;
    int* P = new int[N];
    for (int i = 0; i < N; i++) {
        std::cin >> P[i];
    }

    int result = tarifa(X, N, P);

    std::cout << result << std::endl;

    return 0;
}