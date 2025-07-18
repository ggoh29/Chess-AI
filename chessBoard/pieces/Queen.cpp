#include "Queen.h"

Queen::Queen(bool colour) : colour(colour), mv(new Move()){}

int Queen::pieceEnum(){
        return colour ? 5 : 13;
};  

std::string Queen::pieceAscii(){
        return colour ? "♛" : "♕";
};

std::vector<int>* Queen::getMoves(char i, char j, BoardRepr* board, int previousMove){
    std::vector<int> *moves = new std::vector<int>();
    for (char x = -1; x <= 1; x ++){
        for (char y = -1; y <= 1; y++){
            char xx = i + x;
            char yy = j + y;
            if (x == 0 && y == 0){
                continue;
            }
            for (;0 <= xx && xx < 8 && 0 <= yy && yy < 8;){
                bool cond = !isSameTeam(colour, board->getPieceEnumAt(xx, yy));
                if (board->getPieceEnumAt(xx, yy) == 0 | cond){
                    std::array<char, 4> move = {i, j, xx, yy};
                    int moveEncoded = mv->encodeMove(move);
                    moves->push_back(moveEncoded);
                    if (cond){
                        break;
                    }
                    xx = xx + x;
                    yy = yy + y;
                } else {
                    break;
                }
            }
        }
    }
    return moves;
}; 