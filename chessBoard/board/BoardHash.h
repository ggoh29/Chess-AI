#ifndef BOARDHASH_H
#define BOARDHASH_H
#include "../pieces/Piece.h"
#include <array>

class BoardHash{
  static std::array<std::array<unsigned long, 64>, 16> hashTable;
  static std::array<unsigned long, 64> blank;
  static std::array<unsigned long, 64> blackPawn;
  static std::array<unsigned long, 64> whitePawn;
  static std::array<unsigned long, 64> blackKnight;
  static std::array<unsigned long, 64> whiteKnight;
  static std::array<unsigned long, 64> blackBishop;
  static std::array<unsigned long, 64> whiteBishop;
  static std::array<unsigned long, 64> blackRook;
  static std::array<unsigned long, 64> whiteRook;
  static std::array<unsigned long, 64> blackQueen;
  static std::array<unsigned long, 64> whiteQueen;
  static std::array<unsigned long, 64> blackKing;
  static std::array<unsigned long, 64> whiteKing;
  public:
    BoardHash();
    unsigned long getHash(std::array<std::array<Piece*, 8>, 8> chessBoard);
};

#endif