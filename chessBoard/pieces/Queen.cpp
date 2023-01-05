#include "Queen.h"

Queen::Queen(bool colour) : colour(colour){}

char Queen::pieceEnum(){
        return colour ? 5 : 13;
    };  

std::string Queen::pieceAscii(){
        return colour ? "♛" : "♕";
    };

int Queen::encodeMove(std::array<int, 4> move){
    int encodedMove = 0;
    for (int i = 0; i < 4; i++){
        encodedMove = (encodedMove << 8) ^ move[i];
    }
    return encodedMove;
};

std::vector<int>* Queen::getMoves(int i, int j, std::array<std::array<Piece*, 8>, 8> chessBoard){
    std::vector<int>* empty = new std::vector<int>();
    return empty;
}; 