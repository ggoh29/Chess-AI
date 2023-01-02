#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook:public Piece{
  bool colour; 
  public:
    Rook(bool colour);
    char pieceEnum();     
    std::string pieceAscii();
};

#endif