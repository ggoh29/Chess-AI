#include "Pawn.h"
#include <iostream>

Pawn::Pawn(bool colour) : colour(colour), mv(new Move()){}


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


std::vector<int>* Pawn::getMoves(int i, int j, std::array<std::array<Piece*, 8>, 8> chessBoard, int previousMove){
    std::vector<int> *moves = new std::vector<int>();
    int firstRow = colour ? 6 : 1;
    int movesAhead = (i == firstRow) ? 3 : 2;
    int colourMultiplier = colour ? -movesAhead : movesAhead;
    for (int k = colour ? i - 1 : i + 1 ; k != i + colourMultiplier ; colour ? k-- : k++){
        if ((chessBoard[k][j] -> pieceEnum()) == 0){
            std::array<int, 4> move = {i, j, k, j};
            int moveEncoded = mv->encodeMove(move);
            moves->push_back(moveEncoded);
        } else {
            break;
        }
    }

    int x = colour ? i - 1 : i + 1;
    for (int k = 0; k <= 1; k ++){
        int y = k ? j - 1 : j + 1;
        if (0 <= x && x < 8 && 0 <= y && y < 8){
            if (!isSameTeam(colour, chessBoard[x][y])){
                std::array<int, 4> move = {i, j, x, y};
                int moveEncoded = mv->encodeMove(move);
                moves->push_back(moveEncoded);
            }
        }
    }

    if (i == (colour ? 3 : 4)){
        for (int k = 0; k <= 1; k ++){
            int y = k ? j - 1 : j + 1;
            if (0 <= y && y < 8){
                std::array<int, 4> enPassantPawnMove = {colour ? 1 : 6, y, i, y};
                if (previousMove == mv->encodeMove(enPassantPawnMove) && chessBoard[i][y]->pieceEnum() == (colour ? 9 : 1)){
                    std::array<int, 4> move = {i, j, colour ? i - 1 : i + 1, y};
                    moves->push_back(mv->encodeEnPassant(move));
               }
            }
        }
    }

    if (i == (colour ? 1 : 6)){
        if ((chessBoard[colour ? i - 1 : i + 1][j] -> pieceEnum()) == 0){
            int mask =colour ? 0 : 8;
            for (int x = 2; x < 7; x++){
                std::array<int, 4> move = {i, j, colour ? i - 1 : i + 1, j};
                moves->push_back(mv->encodePromotion(move, mask ^ x));
            }
        }
    }
    return moves;
}; 
