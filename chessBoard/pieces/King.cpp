#include "King.h"

King::King(bool colour) : colour(colour){}

int King::pieceEnum(){
        return colour ? 6 : 14;
    };

std::string King::pieceAscii(){
        return colour ? "♚" : "♔";
    };

int King::encodeMove(std::array<int, 4> move){
    int encodedMove = 0;
    for (int i = 0; i < 4; i++){
        encodedMove = (encodedMove << 4) ^ move[i];
    }
    return encodedMove;
};

std::vector<int>* King::getMoves(int i, int j, std::array<std::array<Piece*, 8>, 8> chessBoard, int previousMove){
    std::vector<int>* empty = new std::vector<int>();
    return empty;
}; 