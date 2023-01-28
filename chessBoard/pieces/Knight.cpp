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

std::vector<int>* Knight::getMoves(int i, int j, std::array<Piece*, 64> chessBoard, int previousMove){
    std::vector<int> *moves = new std::vector<int>();
    for (int x_dir : {-1, +1}){
        for (int y_dir : {-1, +1}){
            for (int x_mag : {1, 2}){
                for (int y_mag : {1, 2}){
                    int x = i + x_mag * x_dir;
                    int y = j + y_mag * y_dir;
                    if (x_mag != y_mag && 0 <= x && x < 8 && 0 <= y && y < 8 && ((chessBoard[x * 8 + y] -> pieceEnum()) == 0 || !isSameTeam(colour, chessBoard[x * 8 + y]))){
                        std::array<int, 4> move = {i, j, x, y};
                        int moveEncoded = mv->encodeMove(move);
                        moves->push_back(moveEncoded);
                    }
                }
            }
        }
    }
    return moves;
}; 