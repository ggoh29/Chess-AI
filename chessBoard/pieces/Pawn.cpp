#include "Pawn.h"
#include <iostream>

Pawn::Pawn(bool colour) : colour(colour), mv(new Move()){}

int Pawn::pieceEnum(){
        return colour ? 1 : 9;
    };

std::string Pawn::pieceAscii(){
        return colour ? "♟︎" : "♙";
    };


std::vector<int>* Pawn::getMoves(char i, char j, BoardRepr* board, int previousMove){
    std::vector<int> *moves = new std::vector<int>();
    char firstRow = colour ? 6 : 1;
    char reverseFirstRow = colour ? 1 : 6;
    char movesAhead = (i == firstRow) ? 3 : 2;
    char colourMultiplier = colour ? -movesAhead : movesAhead;
    char singleStepI = colour ? i - 1 : i + 1;
    for (char k = colour ? i - 1 : i + 1 ; k != i + colourMultiplier ; colour ? k-- : k++){
        if (board->getPieceEnumAt(k, j) == 0){
            if (i == (colour ? 1 : 6)){
                if (board->getPieceEnumAt(singleStepI, j) == 0){
                    char mask = colour ? 0 : 8;
                    for (char x = 2; x < 6; x++){
                        
                        std::array<char, 4> move = {i, j, singleStepI, j};
                        moves->push_back(mv->encodePromotion(move, mask ^ x));
                    }
                }
            } else {
                std::array<char, 4> move = {i, j, k, j};
                int moveEncoded = mv->encodeMove(move);
                moves->push_back(moveEncoded);
            }
        } else {
            break;
        }
    }

    char x = colour ? i - 1 : i + 1;
    for (char k = 0; k <= 1; k ++){
        char y = k ? j - 1 : j + 1;
        if (0 <= x && x < 8 && 0 <= y && y < 8 && !isSameTeam(colour, board -> getPieceEnumAt(x, y))){
            if (i == reverseFirstRow){
                char mask = colour ? 0 : 8;
                for (char z = 2; z < 6; z++){
                    std::array<char, 4> move = {i, j, x, y};
                    moves->push_back(mv->encodePromotion(move, mask ^ z));
                }
            } else {
                std::array<char, 4> move = {i, j, x, y};
                int moveEncoded = mv->encodeMove(move);
                moves->push_back(moveEncoded);
            }
        }
    }

    if (i == (colour ? 3 : 4)){
        for (char k = 0; k <= 1; k ++){
            char y = k ? j - 1 : j + 1;
            if (0 <= y && y < 8){
                
                std::array<char, 4> enPassantPawnMove = {reverseFirstRow, y, i, y};
                if (previousMove == mv->encodeMove(enPassantPawnMove) && board -> getPieceEnumAt(i, y) == (colour ? 9 : 1)){
                    std::array<char, 4> move = {i, j, singleStepI, y};
                    moves->push_back(mv->encodeEnPassant(move));
               }
            }
        }
    }

    return moves;
}; 
