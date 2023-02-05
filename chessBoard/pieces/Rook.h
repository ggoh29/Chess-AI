#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook:public Piece{
  bool colour; 
  Move* mv;
  public:
    Rook(bool colour);
    int pieceEnum();     
    std::string pieceAscii();
    std::vector<int>* getMoves(int i, int j, BoardRepr* board, int previousMove);  
};

#endif