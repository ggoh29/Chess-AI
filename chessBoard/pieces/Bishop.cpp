#include "Bishop.h"

Bishop::Bishop(bool colour) : colour(colour), mv(new Move()){}

int Bishop::pieceEnum(){
        return colour ? 2 : 10;
};

std::string Bishop::pieceAscii(){
        return colour ? "♝" : "♗";
};

std::vector<int>* Bishop::getMoves(char i, char j, BoardRepr* board, int previousMove){
    std::vector<int> *moves = new std::vector<int>();
    for (char x = 0; x <= 1; x ++){
        for (char y = 0; y <= 1; y++){
            char xx = x ? i + 1 : i - 1;
            char yy = y ? j + 1 : j - 1;
            while (0 <= xx && xx < 8 && 0 <= yy && yy < 8){
                bool cond = !isSameTeam(colour, board -> getPieceEnumAt(xx, yy));
                if (board -> getPieceEnumAt(xx, yy) == 0 | cond){
                    std::array<char, 4> move = {i, j, xx, yy};
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