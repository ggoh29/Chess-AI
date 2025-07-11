#ifndef BOARDREPR_H
#define BOARDREPR_H
#include "../moves/Moves.h"
#include <array>

class BoardRepr{

  std::array<int, 8> boardRepr;
  public:
    BoardRepr(std::array<int, 8> boardRepr);
    char getPieceEnumAt(char x, char y);
    void putPieceEnum(char x, char y, char e);
};

#endif