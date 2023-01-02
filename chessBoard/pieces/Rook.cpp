#include "Rook.h"

Rook::Rook(bool colour) : colour(colour){}

char Rook::pieceEnum(){
        return colour ? 4 : 12;
    };  
std::string Rook::pieceAscii(){
        return colour ? "♜" : "♖";
    };
