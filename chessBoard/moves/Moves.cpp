#include "Moves.h"
#include <iostream>
Move::Move(){};

int Move::encodeMove(std::array<int, 4> move){
    int encodedMove = 0;
    std::cout << move[0] << " " << move[1] << " " << move[2] << " " << move[3] << std::endl;
    for (int i = 0; i < 4; i++){
        encodedMove = (encodedMove << 4) ^ move[i];
    }
    return encodedMove;
};

int Move::encodeEnPassant(std::array<int, 4> move){
    int encodedMove = 1 << 31;
    std::cout << move[0] << " " << move[1] << " " << move[2] << " " << move[3] << std::endl;
    for (int i = 0; i < 4; i++){
        encodedMove = (encodedMove << 4) ^ move[i];
    }
    return encodedMove;
};

int Move::encodePromotion(std::array<int, 4> move, int promotedPiece){
    int encodedMove = 1 << 30;
    std::cout << move[0] << " " << move[1] << " " << move[2] << " " << move[3] << std::endl;
    for (int i = 0; i < 4; i++){
        encodedMove = (encodedMove << 4) ^ move[i];
    }
    return encodedMove;
};