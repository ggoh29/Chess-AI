#ifndef MOVES_H
#define MOVES_H
#include <array>

class Move{
  bool colour;
  public:
    Move(); 
    int encodeMove(std::array<int, 4> move);
    int encodeEnPassant(std::array<int, 4> move);
    int encodePromotion(std::array<int, 4> move, int promotedPiece);
    std::array<int, 4> decodeMove(int encodedMove);
    std::array<int, 4> decodePromotion(int encodedMove);
};

#endif