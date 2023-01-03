#include "Knight.h"

Knight::Knight(bool colour) : colour(colour){}

char Knight::pieceEnum(){
        return colour ? 3 : 11;
    };

std::string Knight::pieceAscii(){
        return colour ? "♞" : "♘";
    };

std::vector<int> Knight::getMoves(int i, int j, std::array<std::array<Piece*, 8>, 8> chessBoard){
    std::vector<int> empty;
    return empty;
}; 