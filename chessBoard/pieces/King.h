#ifndef KING_H
#define KING_H

#include "Piece.h"

class King:public Piece{
  bool colour; 
  public:
    King(bool colour);
    char pieceEnum();     
    std::string pieceAscii();
};

#endif