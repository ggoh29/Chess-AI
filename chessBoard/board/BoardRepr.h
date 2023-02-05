#ifndef BOARDREPR_H
#define BOARDREPR_H
#include "../moves/Moves.h"
#include <array>

class BoardRepr{

  std::array<int, 8> boardRepr;
  public:
    BoardRepr(std::array<int, 8> boardRepr);
    int getPieceEnumAt(int x, int y);
    void putPieceEnum(int x, int y, int e);
};

#endif