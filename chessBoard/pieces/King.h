#ifndef KING_H
#define KING_H

#include "Piece.h"

class King:public Piece{
  bool colour; 
  Move* mv;
  public:
    King(bool colour);
    int pieceEnum();
    std::string pieceAscii();
    std::vector<int>* getMoves(int i, int j, BoardRepr* board, int previousMove);  
};

#endif