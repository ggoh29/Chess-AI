#include "Rook.h"

Rook::Rook(bool colour) : colour(colour){}

char Rook::pieceEnum(){
        return colour ? 4 : 12;
    };

std::string Rook::pieceAscii(){
        return colour ? "♜" : "♖";
    };

int Rook::encodeMove(std::array<int, 4> move){
    int encodedMove = 0;
    for (int i = 0; i < 4; i++){
        encodedMove = (encodedMove << 8) ^ move[i];
    }
    return encodedMove;
};

std::vector<int>* Rook::getMoves(int i, int j, std::array<std::array<Piece*, 8>, 8> chessBoard){
    std::vector<int>* empty = new std::vector<int>();
    return empty;
}; 