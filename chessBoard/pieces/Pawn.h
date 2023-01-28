#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn:public Piece{
  bool colour;
  Move* mv;
  public:
    Pawn(bool colour);
    int pieceEnum();
    bool isSameTeam(bool colour, Piece* piece);
    std::string pieceAscii();
    std::vector<int>* getMoves(int i, int j, std::array<Piece*, 64> chessBoard, int previousMove);
};

#endif