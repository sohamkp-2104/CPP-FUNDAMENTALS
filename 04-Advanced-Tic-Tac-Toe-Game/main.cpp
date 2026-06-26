#include <iostream>
#include "Game.h"

using namespace std;

int main() {
    Game game;
    int move;
    char playAgain;

    do {
        game.resetBoard();

        while (true) {
            game.displayBoard();

            cout << "Your Move (X) enter 1-9: ";
            cin >> move;

            if (!game.makeMove(move, 'X')) {
                cout << "Invalid Move!\n";
                continue;
            }

            if (game.checkWin('X')) {
                game.displayBoard();
                cout << " You Win!\n";
                break;
            }

            if (game.isDraw()) {
                game.displayBoard();
                cout << " Draw!\n";
                break;
            }

            // AI Move
            int aiMove = game.findBestMove();
            game.makeMove(aiMove, 'O');

            cout << "AI played: " << aiMove << "\n";

            if (game.checkWin('O')) {
                game.displayBoard();
                cout << " AI Wins!\n";
                break;
            }

            if (game.isDraw()) {
                game.displayBoard();
                cout << " Draw!\n";
                break;
            }
        }

        cout << "Play Again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}