#include "King.h"

King::King(bool colour):colour(colour),mv(new Move()){}

int King::pieceEnum(){
        return colour ? 6 : 14;
    };

std::string King::pieceAscii(){
        return colour ? "♚" : "♔";
    };


std::vector<int>* King::getMoves(int i, int j, std::array<std::array<Piece*, 8>, 8> chessBoard, int previousMove){
    std::vector<int>* empty = new std::vector<int>();
    return empty;
}; 