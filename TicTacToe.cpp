#include <cassert>
#include <iostream>
#include "TicTacToe.h"

static void playMoves(TicTacToe& g, std::initializer_list<std::pair<int,int>> moves) {
    for (auto rc : moves) {
        bool ok = g.makeMove(rc.first, rc.second);
        assert(ok && "Expected move to be valid during helper sequence");
    }
}

void test_initial_state() {
    TicTacToe game;
    assert(game.getCurrentPlayer() == 'X');
    assert(game.getMoveCount() == 0);
    for (int r = 0; r < 3; ++r)
        for (int c = 0; c < 3; ++c)
            assert(game.getCell(r,c) == ' ');
assert(game.isGameOver() == false);
std::cout << " Initial state test passed\n";
}

void test_valid_move() {
    TicTacToe game;
    bool ok = game.makeMove(0,0);
    assert(ok);
    assert(game.getCell(0,0) == 'X');
    assert(game.CurrentPlayer() == 'o');
    assert(game.getMoveCount() == 1);
    std::cout << " Valid move test passed\n";
}

void test_invalid_moves() {
    TicTacToe game;
    assert(game.makeMove(0,0) == true);
    assert(game.makeMove(0,0) == false);
    assert(game.makeMove(-1,0) == false);
    assert(game.makeMove(0,-1) == false);
    assert(game.makeMove(3,0) == false);
    assert(game.makeMove(0,3) == false);

    TicTacToe g2;
    playMoves(g2, {{0,0},{1,0},{0,1},{1,1},{0,2}});
    assert(g2.isGameOver() == true);
    assert(g2.getWinner() == 'X');
    assert(g2.makeMove(2,2) == false);
    std::cout << " Invalid moves test passed\n";
}

void test_winner_detection_row() {
    TicTacToe game;
    playMoves(game, {{0,0},{1,0},{0,1},{0,2}};
    assert(game.getWinner() == 'X');
    assert(game.isGameOver() == true);
    std::cout << " Winner detection (row) test passed\n";
}

void test_winner_detection_column() {
    TicTacToe game;
    playMoves(game, {{0,1},{0,0},{1,1},{1,0},{2,2},{2,0}});
    assert(game.getWinner() == 'o');
    assert(game.isGameOver() == true);
    std::cout << " Winner detection (column) test passed\n";
}

void test_full_board_no_winner() {
    TicTacToe game;
    playMoves(game, {
        {0,0},{0,1},{0,2},
        {1,0},{1,1},{1,2},
        {2,0},{2,1},{2,2}
    });
    assert(game.getWinner() ==' ');
    assert(game.isFull() == true);
    assert(game.isGameOver() == true);
    std::cout << " Full board no winner test passed\n";
}

int main() {
    std::cout << "Running Tic-Tac-toe test...\n\n";
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
        
