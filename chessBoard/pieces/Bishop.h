#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop:public Piece{
  bool colour; 
  public:
    Bishop(bool colour);
    char pieceEnum();     
    std::string pieceAscii();
};

#endif