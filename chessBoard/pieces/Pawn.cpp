#include "Pawn.h"

Pawn::Pawn(bool colour) : colour(colour){}

char Pawn::pieceEnum(){
        return colour ? 1 : 9;
    };  
std::string Pawn::pieceAscii(){
        return colour ? "♟︎" : "♙";
    };
