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
    std::vector<int>* getMoves(char i, char j, BoardRepr* board, int previousMove);
};

#endif