#include "Rook.h"
#include <iostream>

Rook::Rook(bool colour) : colour(colour), mv(new Move()){}

bool Rook::isSameTeam(bool colour, Piece* piece){
    if (piece->pieceEnum() == 0){
        return true;
    }
    int mask = 8;
    return ((((piece -> pieceEnum()) & mask) >> 3) != colour);
}

int Rook::pieceEnum(){
        return colour ? 4 : 12;
};

std::string Rook::pieceAscii(){
        return colour ? "♜" : "♖";
};

std::vector<int>* Rook::getMoves(int i, int j, std::array<std::array<Piece*, 8>, 8> chessBoard, int previousMove){
    std::vector<int> *moves = new std::vector<int>();
    int directions[4][2] = {{+1, 0}, {-1, 0}, {0, +1}, {0, -1}};
    for (auto direction : directions){
        int xx = i + direction[0];
        int yy = j + direction[1];
        for (;0 <= xx && xx < 8 && 0 <= yy && yy < 8;){
            if ((chessBoard[xx][yy] -> pieceEnum()) == 0 | !isSameTeam(colour, chessBoard[xx][yy])){
                std::array<int, 4> move = {i, j, xx, yy};
                int moveEncoded = mv->encodeMove(move);
                moves->push_back(moveEncoded);
                xx += direction[0];
                yy += direction[1];
            } else {
                break;
            }
        }
    }
    return moves;
}; 