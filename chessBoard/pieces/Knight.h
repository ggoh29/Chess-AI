#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.h"

class Knight:public Piece{
  bool colour;
  Move* mv;
  public:
    Knight(bool colour);
    int pieceEnum();
    bool isSameTeam(bool colour, Piece* piece);
    std::string pieceAscii();
    std::vector<int>* getMoves(int i, int j, std::array<std::array<Piece*, 8>, 8> chessBoard, int previousMove);
};

#endif