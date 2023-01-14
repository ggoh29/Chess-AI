#include "Rook.h"

Rook::Rook(bool colour) : colour(colour), mv(new Move()){}

bool Rook::isSameTeam(bool colour, Piece* piece){
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
    Piece* piece = chessBoard[i][j];
    std::vector<int> *moves = new std::vector<int>();
    int directions[4][2] = {{+1, 0}, {-1, 0}, {0, +1}, {0, -1}};
    for (auto direction : directions){
        int xx = i;
        int yy = j;
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