#include "Piece.h"

Piece::Piece():mv(new Move()){};

bool Piece::isSameTeam(bool colour, int pieceEnum){
    if (pieceEnum == 0){
        return true;
    }
    char mask = 8;
    return (((pieceEnum & mask) >> 3) != colour);
}

int Piece::pieceEnum(){
        return 0;
};        

std::string Piece::pieceAscii(){
        return " ";
};

std::vector<int>* Piece::getMoves(char i, char j, BoardRepr* board, int previousMove){
    std::vector<int>* empty = new std::vector<int>();
    return empty;
}; 