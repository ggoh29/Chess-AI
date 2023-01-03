#include "Queen.h"

Queen::Queen(bool colour) : colour(colour){}

char Queen::pieceEnum(){
        return colour ? 5 : 13;
    };  

std::string Queen::pieceAscii(){
        return colour ? "♛" : "♕";
    };

std::vector<int> Queen::getMoves(int i, int j, std::array<std::array<Piece*, 8>, 8> chessBoard){
    std::vector<int> empty;
    return empty;
}; 