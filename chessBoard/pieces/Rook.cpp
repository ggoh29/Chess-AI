#include "Rook.h"
#include <iostream>

static const char directions[4][2] = {{+1, 0}, {-1, 0}, {0, +1}, {0, -1}};

Rook::Rook(bool colour) : colour(colour), mv(new Move()){}

int Rook::pieceEnum(){
        return colour ? 4 : 12;
};

std::string Rook::pieceAscii(){
        return colour ? "♜" : "♖";
};

std::vector<int>* Rook::getMoves(char i, char j, BoardRepr* board, int previousMove){
    std::vector<int> *moves = new std::vector<int>();
    for (auto direction : directions){
        char xx = i + direction[0];
        char yy = j + direction[1];
        for (;0 <= xx && xx < 8 && 0 <= yy && yy < 8;){
            bool cond = !isSameTeam(colour, board->getPieceEnumAt(xx, yy));
            if (board->getPieceEnumAt(xx, yy) == 0 | cond){
                std::array<char, 4> move = {i, j, xx, yy};
                int moveEncoded = mv->encodeMove(move);
                moves->push_back(moveEncoded);
                if (cond){
                    break;
                }
                xx += direction[0];
                yy += direction[1];
            } else {
                break;
            }
        }
    }
    return moves;
}; 