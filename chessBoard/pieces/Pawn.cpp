#include "Pawn.h"
#include <iostream>

Pawn::Pawn(bool colour) : colour(colour){}

char Pawn::pieceEnum(){
        return colour ? 1 : 9;
    };

std::string Pawn::pieceAscii(){
        return colour ? "♟︎" : "♙";
    };

int Pawn::encodeMove(std::array<int, 4> move){
    int encodedMove = 0;
    for (int i = 0; i < 4; i++){
        encodedMove = (encodedMove << 8) ^ move[i];
    }
    return encodedMove;
};

std::vector<int>* Pawn::getMoves(int i, int j, std::array<std::array<Piece*, 8>, 8> chessBoard){
    Piece* piece = chessBoard[i][j];
    std::vector<int> *moves = new std::vector<int>();
    int first_row = colour ? 6 : 1;
    int moves_ahead = (i == first_row) ? 3 : 2;
    int colourMultiplier = colour ? -moves_ahead : moves_ahead;
    for (int k = i; k != i + colourMultiplier ; colour ? k-- : k++){
        if ((chessBoard[k][j] -> pieceEnum()) == 0){
            std::array<int, 4> move = {i, j, k, j};
            int moveEncoded = piece->encodeMove(move);
            moves->push_back(moveEncoded);
        }
    }
    return moves;
}; 
