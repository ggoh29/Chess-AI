#include "King.h"

King::King(bool colour) : colour(colour){}

char King::pieceEnum(){
        return colour ? 6 : 14;
    };  
std::string King::pieceAscii(){
        return colour ? "♚" : "♔";
    };