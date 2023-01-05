#include "Bishop.h"

Bishop::Bishop(bool colour) : colour(colour){}

char Bishop::pieceEnum(){
        return colour ? 2 : 10;
    };
    
std::string Bishop::pieceAscii(){
        return colour ? "♝" : "♗";
    };

int Bishop::encodeMove(std::array<int, 4> move){
    int encodedMove = 0;
    for (int i = 0; i < 4; i++){
        encodedMove = (encodedMove << 8) ^ move[i];
    }
    return encodedMove;
};

std::vector<int>* Bishop::getMoves(int i, int j, std::array<std::array<Piece*, 8>, 8> chessBoard){
    std::vector<int>* empty = new std::vector<int>();
    return empty;
}; 