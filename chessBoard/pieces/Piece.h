#ifndef PIECE_H
#define PIECE_H
#include "../moves/Moves.h"
#include "../board/BoardRepr.h"
#include <string>
#include <vector>
#include <array>

class Piece{
  bool colour;
  Move* mv;
  public:
    Piece(); 
    bool isSameTeam(bool color, int pieceEnum);
    virtual int pieceEnum();
    virtual std::string pieceAscii();
    virtual std::vector<int>* getMoves(int i, int j, BoardRepr* board, int previousMove);
};

#endif