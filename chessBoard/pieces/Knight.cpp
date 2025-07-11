#include "Knight.h"

static const char directions[8][2] = {{+1, +2}, {+1, -2}, {+2, -1}, {+2, +1}, {-1, +2}, {-1, -2}, {-2, -1}, {-2, +1}};

Knight::Knight(bool colour) : colour(colour), mv(new Move()){}

int Knight::pieceEnum(){
        return colour ? 3 : 11;
};

std::string Knight::pieceAscii(){
        return colour ? "♞" : "♘";
};

std::vector<int>* Knight::getMoves(char i, char j, BoardRepr* board, int previousMove){
    std::vector<int> *moves = new std::vector<int>();
    for (auto direction : directions){
        char x = i + direction[0];
        char y = j + direction[1];
        if (0 <= x && x < 8 && 0 <= y && y < 8 && (board -> getPieceEnumAt(x, y) == 0 || !isSameTeam(colour, board->getPieceEnumAt(x, y)))){
            std::array<char, 4> move = {i, j, x, y};
            int moveEncoded = mv->encodeMove(move);
            moves->push_back(moveEncoded);
        }
    }
    return moves;
}; 