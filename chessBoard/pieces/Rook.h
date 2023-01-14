#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook:public Piece{
  bool colour; 
  Move* mv;
  public:
    Rook(bool colour);
    bool isSameTeam(bool colour, Piece* piece);
    int pieceEnum();     
    std::string pieceAscii();
    std::vector<int>* getMoves(int i, int j, std::array<std::array<Piece*, 8>, 8> chessBoard, int previousMove);  
};

#endif