#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.h"

class Knight:public Piece{
  bool colour; 
  public:
    Knight(bool colour);
    char pieceEnum();     
    std::string pieceAscii();
    std::vector<int> getMoves(int i, int j, std::array<std::array<Piece*, 8>, 8> chessBoard);  
};

#endif