#include "Pawn.h"
#include <iostream>

Pawn::Pawn(bool colour) : colour(colour){}


bool Pawn::isSameTeam(bool colour, Piece* piece){
    int mask = 8;
    return ((((piece -> pieceEnum()) & mask) >> 3) != colour);
}

int Pawn::pieceEnum(){
        return colour ? 1 : 9;
    };

std::string Pawn::pieceAscii(){
        return colour ? "♟︎" : "♙";
    };

int Pawn::encodeMove(std::array<int, 4> move){
    int encodedMove = 0;
    for (int i = 0; i < 4; i++){
        encodedMove = (encodedMove << 4) ^ move[i];
    }
    return encodedMove;
};

std::vector<int>* Pawn::getMoves(int i, int j, std::array<std::array<Piece*, 8>, 8> chessBoard){
    std::vector<int> *moves = new std::vector<int>();
    int first_row = colour ? 6 : 1;
    int moves_ahead = (i == first_row) ? 3 : 2;
    int colourMultiplier = colour ? -moves_ahead : moves_ahead;
    for (int k = colour ? i - 1 : i + 1 ; k != i + colourMultiplier ; colour ? k-- : k++){
        if ((chessBoard[k][j] -> pieceEnum()) == 0){
            std::array<int, 4> move = {i, j, k, j};
            int moveEncoded = encodeMove(move);
            moves->push_back(moveEncoded);
        } else {
            break;
        }
    }
    return moves;
}; 
