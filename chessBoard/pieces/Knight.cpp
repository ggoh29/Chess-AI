#include "Knight.h"

Knight::Knight(bool colour) : colour(colour){}

char Knight::pieceEnum(){
        return colour ? 3 : 11;
    };

std::string Knight::pieceAscii(){
        return colour ? "♞" : "♘";
    };

int Knight::encodeMove(std::array<int, 4> move){
    int encodedMove = 0;
    for (int i = 0; i < 4; i++){
        encodedMove = (encodedMove << 8) ^ move[i];
    }
    return encodedMove;
};

std::vector<int>* Knight::getMoves(int i, int j, std::array<std::array<Piece*, 8>, 8> chessBoard){
    std::vector<int>* empty = new std::vector<int>();
    return empty;
}; 