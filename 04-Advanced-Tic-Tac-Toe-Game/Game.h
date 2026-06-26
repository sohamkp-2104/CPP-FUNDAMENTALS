#ifndef GAME_H
#define GAME_H

#include <vector>
using namespace std;

class Game {
private:
    vector<vector<char>> board;

public:
    Game();

    void displayBoard();
    bool makeMove(int pos, char player);
    bool checkWin(char player);
    bool isDraw();
    void resetBoard();

    int minimax(bool isAI);
    int findBestMove();
};

#endif