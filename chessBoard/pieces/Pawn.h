#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn:public Piece{
  bool colour; 
  public:
    Pawn(bool colour);
     char pieceEnum();     
    std::string pieceAscii();
    int encodeMove(std::array<int, 4> move);
    std::vector<int>* getMoves(int i, int j, std::array<std::array<Piece*, 8>, 8> chessBoard);  
};

#endif