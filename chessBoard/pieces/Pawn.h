#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn:public Piece{
  bool colour;
  Move* mv;
  public:
    Pawn(bool colour);
    int pieceEnum();
    std::string pieceAscii();
    std::vector<int>* getMoves(char i, char j, BoardRepr* board, int previousMove);
};

#endif