#ifndef BOARDHASH_H
#define BOARDHASH_H
#include "../pieces/Piece.h"
#include "./BoardRepr.h"
#include <array>

class BoardHash{
  static const int index[16];
  static const std::array<unsigned long, 64 * 13> hashTable;
  public:
    BoardHash();
    unsigned long getHash(BoardRepr* board);
};

#endif