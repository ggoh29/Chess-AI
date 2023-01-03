#include "Rook.h"

Rook::Rook(bool colour) : colour(colour){}

char Rook::pieceEnum(){
        return colour ? 4 : 12;
    };

std::string Rook::pieceAscii(){
        return colour ? "♜" : "♖";
    };

std::vector<int> Rook::getMoves(int i, int j, std::array<std::array<Piece*, 8>, 8> chessBoard){
    std::vector<int> empty;
    return empty;
}; 
