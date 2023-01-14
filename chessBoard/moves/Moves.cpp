#include "Moves.h"
#include <iostream>
Move::Move(){};

int Move::encodeMove(std::array<int, 4> move){
    int encodedMove = 0;
    for (int i = 0; i < 4; i++){
        encodedMove = (encodedMove << 4) ^ move[i];
    }
    return encodedMove;
};

int Move::encodeEnPassant(std::array<int, 4> move){
    int encodedMove = 1 << 31;
    for (int i = 0; i < 4; i++){
        encodedMove = (encodedMove << 4) ^ move[i];
    }
    return encodedMove;
};

int Move::encodePromotion(std::array<int, 4> move, int promotedPiece){
    int encodedMove = 1 << 30;
    for (int i = 0; i < 4; i++){
        encodedMove = (encodedMove << 4) ^ move[i];
    }
    return encodedMove;
};

int Move::encodeShortCastle(std::array<int, 4> move){
    int encodedMove = 1 << 29;
    for (int i = 0; i < 4; i++){
        encodedMove = (encodedMove << 4) ^ move[i];
    }
    return encodedMove;
};

int Move::encodeLongCastle(std::array<int, 4> move){
    int encodedMove = 1 << 28;
    for (int i = 0; i < 4; i++){
        encodedMove = (encodedMove << 4) ^ move[i];
    }
    return encodedMove;
};