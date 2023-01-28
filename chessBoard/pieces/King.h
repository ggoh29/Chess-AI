#ifndef KING_H
#define KING_H

#include "Piece.h"

class King:public Piece{
  bool colour; 
  Move* mv;
  public:
    King(bool colour);
    int pieceEnum();     
    bool isSameTeam(bool colour, Piece* piece);
    std::string pieceAscii();
    std::vector<int>* getMoves(int i, int j, std::array<Piece*, 64> chessBoard, int previousMove);  
};

#endif