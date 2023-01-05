#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook:public Piece{
  bool colour; 
  public:
    Rook(bool colour);
    char pieceEnum();     
    std::string pieceAscii();
    int encodeMove(std::array<int, 4> move);
    std::vector<int>* getMoves(int i, int j, std::array<std::array<Piece*, 8>, 8> chessBoard);  
};

#endif