#include "Moves.h"

Move::Move(){};

int Move::encodeMove(std::array<int, 4> move){
    int encodedMove = 0;
    for (int i = 0; i < 4; i++){
        encodedMove = (encodedMove << 4) ^ move[i];
    }
    return encodedMove;
};

int Move::encodeEnPassant(std::array<int, 4> move){
    int encodedMove = 0;
    for (int i = 0; i < 4; i++){
        encodedMove = (encodedMove << 4) ^ move[i];
    }
    encodedMove = encodedMove ^ (1 << 31);
    return encodedMove;
};

int Move::encodePromotion(std::array<int, 4> move, int promotedPiece){
    int encodedMove = 0;
    for (int i = 0; i < 4; i++){
        encodedMove = (encodedMove << 4) ^ move[i];
    }
    encodedMove = encodedMove ^ (1 << 30);
    encodedMove = encodedMove ^ (promotedPiece << 16);
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

int Move::decodePromotion(int encodedMove){
    return encodedMove & (15 << 16);
};

std::array<int, 4> Move::decodeMove(int encodedMove){
    int mask = 15;
    std::array<int, 4> move = {0, 0, 0, 0};
    for (int i = 0; i < 4; i++){
        move[3 - i] = (encodedMove >> (i * 4) & mask);
    }
    return move;
};