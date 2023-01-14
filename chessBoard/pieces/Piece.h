#ifndef PIECE_H
#define PIECE_H
#include "../moves/Moves.h"
#include <string>
#include <vector>
#include <array>

class Piece{
  bool colour;
  Move* mv;
  public:
    Piece(); 
    bool isSameTeam(bool color, Piece* piece);
    virtual int pieceEnum();
    virtual std::string pieceAscii();
    virtual std::vector<int>* getMoves(int i, int j, std::array<std::array<Piece*, 8>, 8> chessBoard, int previousMove);
};

#endif