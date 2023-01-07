#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn:public Piece{
  bool colour; 
  public:
    Pawn(bool colour);
    int pieceEnum();
    bool isSameTeam(bool colour, Piece* piece);
    std::string pieceAscii();
    int encodeMove(std::array<int, 4> move);
    int encodeEnPassant(std::array<int, 4> move);
    int encodePromotion(std::array<int, 4> move, int promotedPiece);
    std::vector<int>* getMoves(int i, int j, std::array<std::array<Piece*, 8>, 8> chessBoard, int previousMove);  
};

#endif