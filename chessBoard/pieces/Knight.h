#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.h"

class Knight:public Piece{
  bool colour;
  Move* mv;
  public:
    Knight(bool colour);
    int pieceEnum();
    std::string pieceAscii();
    std::vector<int>* getMoves(char i, char j, BoardRepr* board, int previousMove);
};

#endif