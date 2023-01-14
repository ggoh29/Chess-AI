#include "Bishop.h"

Bishop::Bishop(bool colour) : colour(colour), mv(new Move()){}

int Bishop::pieceEnum(){
        return colour ? 2 : 10;
};

bool Bishop::isSameTeam(bool colour, Piece* piece){
    if (piece->pieceEnum() == 0){
        return true;
    }
    int mask = 8;
    return ((((piece -> pieceEnum()) & mask) >> 3) != colour);
}
    
std::string Bishop::pieceAscii(){
        return colour ? "♝" : "♗";
};

std::vector<int>* Bishop::getMoves(int i, int j, std::array<std::array<Piece*, 8>, 8> chessBoard, int previousMove){
    std::vector<int> *moves = new std::vector<int>();
    for (int x = 0; x <= 1; x ++){
        for (int y = 0; y <= 1; y++){
            int xx = x ? i + 1 : i - 1;
            int yy = y ? j + 1 : j - 1;
            while (0 <= xx && xx < 8 && 0 <= yy && yy < 8){
                bool cond = !isSameTeam(colour, chessBoard[xx][yy]);
                if ((chessBoard[xx][yy] -> pieceEnum()) == 0 | cond){
                    std::array<int, 4> move = {i, j, xx, yy};
                    int moveEncoded = mv->encodeMove(move);
                    moves->push_back(moveEncoded);
                    if (cond){
                        break;
                    }
                    xx = x ? xx + 1 : xx - 1;
                    yy = y ? yy + 1 : yy - 1;
                } else {
                    break;
                }
            }
        }
    }
    return moves;
}; 