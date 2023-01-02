#include "Queen.h"

Queen::Queen(bool colour) : colour(colour){}

char Queen::pieceEnum(){
        return colour ? 5 : 13;
    };  
std::string Queen::pieceAscii(){
        return colour ? "♛" : "♕";
    };