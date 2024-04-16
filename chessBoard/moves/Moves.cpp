#include "Moves.h"
#include <iostream>
Move::Move(){};
static const int move_mask = 0b1111;
static const int castling_mask = 0b111111;
static const unsigned int undo_move_mask = 0b11111111111100001111111111111111;

int Move::encodeMove(std::array<int, 4> move){
    int encodedMove = 0;
    for (int i = 0; i < 4; i++){
        encodedMove = (encodedMove << 4) ^ (move_mask & move[i]);
    }
    return encodedMove;
};

int Move::encodeEnPassant(std::array<int, 4> move){
    int encodedMove = 0;
    for (int i = 0; i < 4; i++){
        encodedMove = (encodedMove << 4) ^ (move_mask & move[i]);
    }
    encodedMove = encodedMove ^ (1 << 31);
    return encodedMove;
};

int Move::encodePromotion(std::array<int, 4> move, int promotedPiece){
    int encodedMove = 0;
    for (int i = 0; i < 4; i++){
        encodedMove = (encodedMove << 4) ^ (move_mask & move[i]);
    }
    encodedMove = encodedMove ^ (1 << 30);
    encodedMove = encodedMove ^ ((move_mask & promotedPiece) << 16);
    return encodedMove;
};

int Move::encodeShortCastle(std::array<int, 4> move){
    int encodedMove = 0;
    for (int i = 0; i < 4; i++){
        encodedMove = (encodedMove << 4) ^ move[i];
    }
    encodedMove = encodedMove ^ (1 << 29);
    return encodedMove;
};

int Move::encodeLongCastle(std::array<int, 4> move){
    int encodedMove = 0;
    for (int i = 0; i < 4; i++){
        encodedMove = (encodedMove << 4) ^ move[i];
    }
    encodedMove = encodedMove ^ (1 << 28);
    return encodedMove;
};

int Move::encodeUndoMove(int encodedMove, int capturedPieceEnum){
    encodedMove = (encodedMove & undo_move_mask) ^ ((move_mask & capturedPieceEnum) << 16);
    return encodedMove;
};

int Move::encodeCastlingState(int encodedMove, int castlingState){
    encodedMove = encodedMove ^ ((castling_mask & castlingState) << 20);
    return encodedMove;
}

int Move::decodeCastlingState(int encodedMove){
    int castlingState = (encodedMove >> 20) & castling_mask;
    return castlingState;
}

int Move::decodePromotion(int encodedMove){
    return (encodedMove >> 16) &  move_mask;
};

std::array<int, 4> Move::decodeMove(int encodedMove){
    int mask = 15;
    std::array<int, 4> move = {0, 0, 0, 0};
    for (int i = 0; i < 4; i++){
        move[3 - i] = (encodedMove >> (i * 4) & mask);
    }
    return move;
};