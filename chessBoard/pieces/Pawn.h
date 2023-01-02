#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn:public Piece{
  bool colour; 
  public:
    Pawn(bool colour);
     char pieceEnum();     
    std::string pieceAscii();
};

#endif