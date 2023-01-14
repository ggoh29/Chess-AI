#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop:public Piece{
  bool colour; 
  Move* mv;
  public:
    Bishop(bool colour);
    bool isSameTeam(bool colour, Piece* piece);
    int pieceEnum();     
    std::string pieceAscii();
    std::vector<int>* getMoves(int i, int j, std::array<std::array<Piece*, 8>, 8> chessBoard, int previousMove);  
};

#endif