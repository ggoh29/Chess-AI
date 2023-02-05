#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen:public Piece{
  bool colour;
  Move* mv;
  public:
    Queen(bool colour);
    int pieceEnum();
    std::string pieceAscii();
    std::vector<int>* getMoves(int i, int j, BoardRepr* board, int previousMove);
};

#endif