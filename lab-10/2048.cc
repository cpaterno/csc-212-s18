#include <iostream>

int** _2048(int** board, int move) {
    /*
     *  Your solution here
     */
}

int main() {

    int** board = new int*[4];
    for (int i = 0; i < 4; i++) {
        board[i] = new int[4];
        for (int j = 0; j < 4; j++) {
            std::cin >> board[i][j];
        }
    }
    int move;
    std::cin >> move;

    int** moved_board;
    moved_board = _2048(board, move);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << moved_board[i][j];
            if (j != 3) std::cout << ' ';
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < 4; i++) {
        delete [] board[i];
        delete [] moved_board[i];
    }
    delete [] board;
    delete [] moved_board;

}