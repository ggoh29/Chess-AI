#ifndef KING_H
#define KING_H

#include "Piece.h"

class King:public Piece{
  bool colour; 
  public:
    King(bool colour);
    char pieceEnum();     
    std::string pieceAscii();
    std::vector<int> getMoves(int i, int j, std::array<std::array<Piece*, 8>, 8> chessBoard);  
};

#endif