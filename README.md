# Tic-Tac-Toe Testing Example

This is a simple Tic-Tac-Toe implementation used for demonstrating:
- Unit testing with CTest
- GitHub workflow (forking, pull requests)
- Merge conflicts

## Building

```bash
mkdir build
cd build
cmake --build . 
make
```

## Running Tests

```bash
ctest --verbose
```

## Merge Conflict Scenario

This repository demonstrates a realistic merge conflict scenario:

**Branch: feature/ai-opponent**
- Adds AI opponent functionality to `TicTacToe.cpp`
- Modifies the `makeMove()` function to track move history

**Branch: feature/undo-move**
- Adds undo functionality to `TicTacToe.cpp`
- Also modifies the `makeMove()` function to save previous state

When both branches are merged, they conflict because they both modify the same `makeMove()` function in different ways.
