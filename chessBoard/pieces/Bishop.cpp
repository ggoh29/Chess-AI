#include "Bishop.h"

Bishop::Bishop(bool colour) : colour(colour){}

char Bishop::pieceEnum(){
        return colour ? 2 : 10;
    };        
std::string Bishop::pieceAscii(){
        return colour ? "♝" : "♗";
    };