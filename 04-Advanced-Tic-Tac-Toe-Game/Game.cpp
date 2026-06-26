#include "Game.h"
#include <iostream>
#include <limits>

using namespace std;

Game::Game() {
    board = vector<vector<char>>(3, vector<char>(3));
    resetBoard();
}

void Game::resetBoard() {
    char c = '1';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = c++;
}

void Game::displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
            if (j < 2) cout << "| ";
        }
        cout << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

bool Game::makeMove(int pos, char player) {
    int r = (pos - 1) / 3;
    int c = (pos - 1) % 3;

    if (board[r][c] != 'X' && board[r][c] != 'O') {
        board[r][c] = player;
        return true;
    }
    return false;
}

bool Game::checkWin(char p) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == p && board[i][1] == p && board[i][2] == p)
            return true;
        if (board[0][i] == p && board[1][i] == p && board[2][i] == p)
            return true;
    }

    if (board[0][0] == p && board[1][1] == p && board[2][2] == p)
        return true;

    if (board[0][2] == p && board[1][1] == p && board[2][0] == p)
        return true;

    return false;
}

bool Game::isDraw() {
    for (auto &row : board)
        for (char c : row)
            if (c != 'X' && c != 'O')
                return false;
    return true;
}

/* ---------------- MINIMAX AI ---------------- */

int Game::minimax(bool isAI) {
    if (checkWin('O')) return 10;
    if (checkWin('X')) return -10;
    if (isDraw()) return 0;

    if (isAI) {
        int best = numeric_limits<int>::min();

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] != 'X' && board[i][j] != 'O') {
                    char backup = board[i][j];
                    board[i][j] = 'O';

                    best = max(best, minimax(false));

                    board[i][j] = backup;
                }
            }
        }
        return best;
    } else {
        int best = numeric_limits<int>::max();

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] != 'X' && board[i][j] != 'O') {
                    char backup = board[i][j];
                    board[i][j] = 'X';

                    best = min(best, minimax(true));

                    board[i][j] = backup;
                }
            }
        }
        return best;
    }
}

int Game::findBestMove() {
    int bestVal = -1000;
    int bestMove = -1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                char backup = board[i][j];
                board[i][j] = 'O';

                int moveVal = minimax(false);

                board[i][j] = backup;

                if (moveVal > bestVal) {
                    bestMove = i * 3 + j + 1;
                    bestVal = moveVal;
                }
            }
        }
    }
    return bestMove;
}