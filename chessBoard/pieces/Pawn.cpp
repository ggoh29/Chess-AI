#include "Pawn.h"

Pawn::Pawn(bool colour) : colour(colour){}

char Pawn::pieceEnum(){
        return colour ? 1 : 9;
    };

std::string Pawn::pieceAscii(){
        return colour ? "♟︎" : "♙";
    };

std::vector<int> Pawn::getMoves(int i, int j, std::array<std::array<Piece*, 8>, 8> chessBoard){
    std::vector<int> empty;
    return empty;
}; 
