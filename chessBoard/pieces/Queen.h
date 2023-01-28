#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen:public Piece{
  bool colour;
  Move* mv;
  public:
    Queen(bool colour);
    bool isSameTeam(bool colour, Piece* piece);
    int pieceEnum();
    std::string pieceAscii();
    std::vector<int>* getMoves(int i, int j, std::array<Piece*, 64> chessBoard, int previousMove);
};

#endif