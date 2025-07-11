#include "Moves.h"
#include <iostream>
Move::Move(){};

int Move::encodeMove(std::array<char, 4> move){
    int encodedMove = 0;
    for (char i = 0; i < 4; i++){
        encodedMove = (encodedMove << 4) ^ (0b1111 & move[i]);
    }
    return encodedMove;
};

int Move::encodeEnPassant(std::array<char, 4> move){
    int encodedMove = 0;
    for (char i = 0; i < 4; i++){
        encodedMove = (encodedMove << 4) ^ (0b1111 & move[i]);
    }
    encodedMove = encodedMove ^ (1 << 31);
    return encodedMove;
};

int Move::encodePromotion(std::array<char, 4> move, int promotedPiece){
    int encodedMove = 0;
    for (char i = 0; i < 4; i++){
        encodedMove = (encodedMove << 4) ^ (0b1111 & move[i]);
    }
    encodedMove = encodedMove ^ (1 << 30);
    encodedMove = encodedMove ^ ((0b1111 & promotedPiece) << 16);
    return encodedMove;
};

int Move::encodeShortCastle(std::array<char, 4> move){
    int encodedMove = 0;
    for (char i = 0; i < 4; i++){
        encodedMove = (encodedMove << 4) ^ move[i];
    }
    encodedMove = encodedMove ^ (1 << 29);
    return encodedMove;
};

int Move::encodeLongCastle(std::array<char, 4> move){
    int encodedMove = 0;
    for (char i = 0; i < 4; i++){
        encodedMove = (encodedMove << 4) ^ move[i];
    }
    encodedMove = encodedMove ^ (1 << 28);
    return encodedMove;
};

int Move::encodeUndoMove(int encodedMove, int capturedPieceEnum){
    encodedMove = (encodedMove & (0b11111111111100001111111111111111)) ^ ((0b1111 & capturedPieceEnum) << 16);
    return encodedMove;
};

int Move::encodeCastlingState(int encodedMove, int castlingState){
    encodedMove = encodedMove ^ ((0b111111 & castlingState) << 20);
    return encodedMove;
}

int Move::decodeCastlingState(int encodedMove){
    int castlingState = (encodedMove >> 20) & 0b111111;
    return castlingState;
}

int Move::decodePromotion(int encodedMove){
    return (encodedMove >> 16) &  0b1111;
};

std::array<char, 4> Move::decodeMove(int encodedMove){
    char mask = 15;
    std::array<char, 4> move = {0, 0, 0, 0};
    for (char i = 0; i < 4; i++){
        move[3 - i] = (encodedMove >> (i * 4) & mask);
    }
    return move;
};