#include "King.h"

King::King(bool colour):colour(colour),mv(new Move()){}

int King::pieceEnum(){
        return colour ? 6 : 14;
};

bool King::isSameTeam(bool colour, Piece* piece){
    if (piece->pieceEnum() == 0){
        return true;
    }
    int mask = 8;
    return ((((piece -> pieceEnum()) & mask) >> 3) != colour);
}

std::string King::pieceAscii(){
        return colour ? "♚" : "♔";
};


std::vector<int>* King::getMoves(int i, int j, std::array<std::array<Piece*, 8>, 8> chessBoard, int previousMove){
    std::vector<int>* empty = new std::vector<int>();
    return empty;
}; 