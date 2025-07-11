#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop:public Piece{
  bool colour;
  Move* mv;
  public:
    Bishop(bool colour);
    int pieceEnum();
    std::string pieceAscii();
    std::vector<int>* getMoves(char i, char j, BoardRepr* board, int previousMove);
};

#endif