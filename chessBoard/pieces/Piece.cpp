#include "Piece.h"

bool isSameTeam(bool colour, Piece* piece){
    int mask = 8;
    return (((piece -> pieceEnum()) ^ mask) == colour);
}

char Piece::pieceEnum(){
        return 0;
    };        

std::string Piece::pieceAscii(){
        return " ";
    };

int Piece::encodeMove(std::array<int, 4> move){
    int encodedMove = 0;
    for (int i = 0; i < 4; i++){
        encodedMove = (encodedMove << 8) ^ move[i];
    }
    return encodedMove;
};

std::vector<int>* Piece::getMoves(int i, int j, std::array<std::array<Piece*, 8>, 8> chessBoard){
    std::vector<int>* empty = new std::vector<int>();
    return empty;
}; 