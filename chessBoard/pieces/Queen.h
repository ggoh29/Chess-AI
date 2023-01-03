#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen:public Piece{
  bool colour; 
  public:
    Queen(bool colour);
    char pieceEnum();     
    std::string pieceAscii();
    std::vector<int> getMoves(int i, int j, std::array<std::array<Piece*, 8>, 8> chessBoard);  
};


#endif