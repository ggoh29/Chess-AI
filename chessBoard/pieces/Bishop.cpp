#include "Bishop.h"

Bishop::Bishop(bool colour) : colour(colour){}

char Bishop::pieceEnum(){
        return colour ? 2 : 10;
    };
    
std::string Bishop::pieceAscii(){
        return colour ? "♝" : "♗";
    };

std::vector<int> Bishop::getMoves(int i, int j, std::array<std::array<Piece*, 8>, 8> chessBoard){
    std::vector<int> empty;
    return empty;
}; 
