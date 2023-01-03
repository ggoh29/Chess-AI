#include "King.h"

King::King(bool colour) : colour(colour){}

char King::pieceEnum(){
        return colour ? 6 : 14;
    };

std::string King::pieceAscii(){
        return colour ? "♚" : "♔";
    };

std::vector<int> King::getMoves(int i, int j, std::array<std::array<Piece*, 8>, 8> chessBoard){
    std::vector<int> empty;
    return empty;
}; 