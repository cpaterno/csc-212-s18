#include <iostream>

int** _2048(int** board, int move) {
    /*
     *  Your solution here
     */
}

int main() {

    // read input
    int board[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cin >> board[i][j];
        }
    }
    int move;
    std::cin >> move;

    
    // TODO your solution goes here
    int moved_board[4][4];
    // TODO
    
    // write output
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << moved_board[i][j];
            if (j != 3) std::cout << ' ';
        }
        std::cout << std::endl;
    }
}
