#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen:public Piece{
  bool colour; 
  public:
    Queen(bool colour);
    char pieceEnum();     
    std::string pieceAscii();
};


#endif