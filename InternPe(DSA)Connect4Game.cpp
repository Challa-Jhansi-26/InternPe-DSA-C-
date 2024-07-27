#include <iostream>
#include <vector>

using namespace std;

const int ROWS = 6;
const int COLS = 7;
const char EMPTY = '.';
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';

void printBoard(vector<vector<char>>& board) {
    for (int r = 0; r < ROWS; ++r) {
        for (int c = 0; c < COLS; ++c) {
            cout << board[r][c] << ' ';
        }
        cout << endl;
    }
    for (int c = 0; c < COLS; ++c) {
        cout << c + 1 << ' ';
    }
    cout << endl;
}

bool makeMove(vector<vector<char>>& board, int col, char player) {
    if (col < 0 || col >= COLS || board[0][col] != EMPTY) {
        return false;
    }
    for (int r = ROWS - 1; r >= 0; --r) {
        if (board[r][col] == EMPTY) {
            board[r][col] = player;
            return true;
        }
    }
    return false;
}

bool checkWin(vector<vector<char>>& board, char player) {
    // Check horizontal
    for (int r = 0; r < ROWS; ++r) {
        for (int c = 0; c < COLS - 3; ++c) {
            if (board[r][c] == player && board[r][c + 1] == player && board[r][c + 2] == player && board[r][c + 3] == player) {
                return true;
            }
        }
    }
    // Check vertical
    for (int r = 0; r < ROWS - 3; ++r) {
        for (int c = 0; c < COLS; ++c) {
            if (board[r][c] == player && board[r + 1][c] == player && board[r + 2][c] == player && board[r + 3][c] == player) {
                return true;
            }
        }
    }
    // Check diagonal (/)
    for (int r = 3; r < ROWS; ++r) {
        for (int c = 0; c < COLS - 3; ++c) {
            if (board[r][c] == player && board[r - 1][c + 1] == player && board[r - 2][c + 2] == player && board[r - 3][c + 3] == player) {
                return true;
            }
        }
    }
    // Check diagonal (\)
    for (int r = 0; r < ROWS - 3; ++r) {
        for (int c = 0; c < COLS - 3; ++c) {
            if (board[r][c] == player && board[r + 1][c + 1] == player && board[r + 2][c + 2] == player && board[r + 3][c + 3] == player) {
                return true;
            }
        }
    }
    return false;
}

bool isFull(vector<vector<char>>& board) {
    for (int c = 0; c < COLS; ++c) {
        if (board[0][c] == EMPTY) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board(ROWS, vector<char>(COLS, EMPTY));
    char currentPlayer = PLAYER1;
    int column;

    while (true) {
        printBoard(board);
        cout << "Player " << (currentPlayer == PLAYER1 ? 1 : 2) << ", enter column (1-" << COLS << "): ";
        cin >> column;
        if (!makeMove(board, column - 1, currentPlayer)) {
            cout << "Invalid move. Try again." << endl;
            continue;
        }
        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            cout << "Player " << (currentPlayer == PLAYER1 ? 1 : 2) << " wins!" << endl;
            break;
        }
        if (isFull(board)) {
            printBoard(board);
            cout << "The game is a draw!" << endl;
            break;
        }
        currentPlayer = (currentPlayer == PLAYER1 ? PLAYER2 : PLAYER1);
    }

    return 0;
}
