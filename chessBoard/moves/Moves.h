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
    int encodeShortCastle(std::array<int, 4> move);
    int encodeLongCastle(std::array<int, 4> move);
    int encodeUndoMove(int encodedMove, int capturedPieceEnum);
    int encodeCastlingState(int encodedMove, int castlingState);
    int decodeCastlingState(int encodedMove);
    std::array<int, 4> decodeMove(int encodedMove);
    int decodePromotion(int encodedMove);
};

#endif