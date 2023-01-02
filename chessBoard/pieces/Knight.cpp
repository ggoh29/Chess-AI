#include "Knight.h"

Knight::Knight(bool colour) : colour(colour){}

char Knight::pieceEnum(){
        return colour ? 3 : 11;
    };        
std::string Knight::pieceAscii(){
        return colour ? "♞" : "♘";
    };