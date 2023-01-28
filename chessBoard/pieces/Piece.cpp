#include "Piece.h"

Piece::Piece():mv(new Move()){};

bool Piece::isSameTeam(bool colour, Piece* piece){
    if (piece->pieceEnum() == 0){
        return true;
    }
    int mask = 8;
    return ((((piece -> pieceEnum()) & mask) >> 3) != colour);
}

int Piece::pieceEnum(){
        return 0;
};        

std::string Piece::pieceAscii(){
        return " ";
};

std::vector<int>* Piece::getMoves(int i, int j, std::array<Piece*, 64> chessBoard, int previousMove){
    std::vector<int>* empty = new std::vector<int>();
    return empty;
}; 