#ifndef BOARDHASH_H
#define BOARDHASH_H
#include "../pieces/Piece.h"
#include <array>

class BoardHash{
  static int index[16];
  static std::array<unsigned long, 64 * 13> hashTable;
  public:
    BoardHash();
    unsigned long getHash(std::array<std::array<Piece*, 8>, 8> chessBoard);
};

#endif