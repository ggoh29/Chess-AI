#include "Knight.h"

Knight::Knight(bool colour) : colour(colour), mv(new Move()){}

int Knight::pieceEnum(){
        return colour ? 3 : 11;
};

bool Knight::isSameTeam(bool colour, Piece* piece){
    if (piece->pieceEnum() == 0){
        return true;
    }
    int mask = 8;
    return ((((piece -> pieceEnum()) & mask) >> 3) != colour);
}

std::string Knight::pieceAscii(){
        return colour ? "♞" : "♘";
};

std::vector<int>* Knight::getMoves(int i, int j, std::array<std::array<Piece*, 8>, 8> chessBoard, int previousMove){
    std::vector<int>* empty = new std::vector<int>();
    return empty;
}; 