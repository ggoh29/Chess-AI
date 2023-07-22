#ifndef BOARDINTERFACE_H
#define BOARDINTERFACE_H
#include "./Board.h"
#include <array>
#include <vector>

class BoardInterface{
  Board* board;
  std::vector<int>* moveslist;
  std::vector<int>* undoMoveslist;
  bool turn;
  public:
    BoardInterface();
    void printBoard(){board->printBoard();};
    void setBoard(Board* b);
    unsigned long getHash();
    void makeMove(int move);
    void makeMove(bool turn, int move);
    void undoMove();
    void undoMove(bool turn);
    void printMovesSoFar();
    void printMove(int move);
    int getWinner(bool turn);
    std::vector<int>* getMoves();
    std::vector<int>* getMoves(bool turn);
    std::vector<int>* getValidMoves();
    std::vector<int>* getValidMoves(bool turn);
};

#endif