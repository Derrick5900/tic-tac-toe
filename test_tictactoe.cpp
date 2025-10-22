#include <cassert>
#include <iostream>
#include "TicTacToe.h"

// Test 1: initial state
void test_initial_state() {
    TicTacToe game;
    assert(game.getCurrentPlayer() == 'X');
    assert(game.getMoveCount() == 0);
    for (int r = 0; r < 3; ++r)
        for (int c = 0; c < 3; ++c)
            assert(game.getCell(r, c) == ' ');
    assert(game.isGameOver() == false);
    std::cout << " Initial state test passed\n";
}

// Test 2: a valid move
void test_valid_move() {
    TicTacToe game;
    bool ok = game.makeMove(0, 0);
    assert(ok);
    assert(game.getCell(0, 0) == 'X');
    assert(game.getCurrentPlayer() == 'O');
    assert(game.getMoveCount() == 1);
    std::cout << " Valid move test passed\n";
}

// Test 3: invalid moves
void test_invalid_moves() {
    TicTacToe game;
    // occupied
    assert(game.makeMove(0, 0) == true);
    assert(game.makeMove(0, 0) == false);
    // out of bounds
    assert(game.makeMove(-1, 0) == false);
    assert(game.makeMove(0, -1) == false);
    assert(game.makeMove(3, 0) == false);
    assert(game.makeMove(0, 3) == false);
    // after game over
    TicTacToe g2;
    assert(g2.makeMove(0,0));
    assert(g2.makeMove(1,0));
    assert(g2.makeMove(0,1));
    assert(g2.makeMove(0,1));
    assert(g2.makeMove(1,1));
    assert(g2.makeMove(0,2));
    assert(g2.isGameOver() == true);
    assert(g2.makeMove(2,2) == false);
    std::cout << Invalid moves test passed\n";
}

// Test 4: row winner (X)
void test_winner_detection_row() {
    TicTacToe game;
    assert(game.makeMove(0,0));
    assert(game.makeMove(1,0));
    assert(game.makeMove(0,1));
    assert(game.makeMove(0,1));
    assert(game.makeMove(1,1));
    assert(game.makeMove(0,2));
    assert(game.getWinner() == 'X');
    assert(game.isGameOver() == true);
    std::cout << " Winner detection (row) test passed\n";
}

// Test 5: colum winner (O)
void test_winner_detection_column() {
    TicTacToe game;
    assert(game.makeMove(0,1));
    assert(game.makeMove(0,0));
    assert(game.makeMove(1,1));
    assert(game.makeMove(1,0));
    assert(game.makeMove(2,2));
    assert(game.makeMove(2,0));
    assert(game.getWinner() == 'O');
    assert(game.isGameOver() == true);
    std::cout << " Winner detection (column) test passed\n";
}

// Test 6: diagonal winner (X)
void test_winner_detection_diagonal() {
    TicTacToe game;
    assert(game.makeMove(0,0));
    assert(game.makeMove(1,1));
    assert(game.makeMove(0,2));
    assert(game.makeMove(2,2));
    assert(game.getWinner() == 'X');
    assert(game.isGameOver() == true);
    std::cout << " Winner detection (diagonal) test passed\n";
}

// Test 7: full board, no winner (tie)
void test_full_board_no_winner() {
        TicTacToe game;
    assert(game.makeMove(0,0));
    assert(game.makeMove(0,1));
    assert(game.makeMove(0,2));
    assert(game.makeMove(1,1));
    assert(game.makeMove(1,0));
    assert(game.makeMove(1,2));
    assert(game.makeMove(2,1));
    assert(game.makeMove(2,0));
    assert(game.makeMove(2,2));
    assert(game.getWinner() == ' ');
    assert(game.isGameOver() == true);
    assert(game.isFull() == true);
    std::cout << " Full board no winner test passed\n";
}

int main() {
    std::cout << "Running Tic-Tac-Toe test...\n\n";
    test_initial_state();
    test_valid_move();
    test_invalid_moves();
    test_winner_detection_row();
    test_winner_detection_column();
    test_winner_detection_diagonal();
    test_full_board_no_winner();
    std::cout << "\nAll test passed! \n";
    return 0;
}


































































