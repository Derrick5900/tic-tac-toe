#include "TicTacToe.h"
#include <iostream>

int main() {
    TicTacToe game;

    std::cout << "Tic-Tac-Toe Game Demo\n";
    std::cout << "=====================\n\n";

    std::cout << "Initial board:\n";
    std::cout << game.toString() << "\n";

    // Play a sample game
    std::cout << "X moves to (0, 0):\n";
    game.makeMove(0, 0);
    std::cout << game.toString() << "\n";

    std::cout << "O moves to (1, 1):\n";
    game.makeMove(1, 1);
    std::cout << game.toString() << "\n";

    std::cout << "X moves to (0, 1):\n";
    game.makeMove(0, 1);
    std::cout << game.toString() << "\n";

    std::cout << "O moves to (2, 2):\n";
    game.makeMove(2, 2);
    std::cout << game.toString() << "\n";

    std::cout << "X moves to (0, 2) - X wins!\n";
    game.makeMove(0, 2);
    std::cout << game.toString() << "\n";

    if (game.getWinner() != ' ') {
        std::cout << "Winner: " << game.getWinner() << "\n";
    }

    return 0;
}
