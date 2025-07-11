#include "King.h"

static const int directions[8][2] = {{1, 0}, {1, 1}, {1, -1}, {0, 1}, {0, -1}, {-1, 0}, {-1, 1}, {-1, -1}};
static const char canlongcastlelist[3] = {1, 2, 3};
static const char canshortcastlelist[2] = {5, 6};

King::King(bool colour):colour(colour),mv(new Move()){}

int King::pieceEnum(){
        return colour ? 6 : 14;
};

std::string King::pieceAscii(){
        return colour ? "♚" : "♔";
};


std::vector<int>* King::getMoves(char i, char j, BoardRepr* board, int previousMove){
    std::vector<int> *moves = new std::vector<int>();
    for (auto dir : directions){
        char x = i + dir[0];
        char y = j + dir[1];
        if (0 <= x && x < 8 && 0 <= y && y < 8 && (board -> getPieceEnumAt(x, y) == 0 || !isSameTeam(colour, board -> getPieceEnumAt(x, y)))){
            std::array<char, 4> move = {i, j, x, y};
            int moveEncoded = mv->encodeMove(move);
            moves->push_back(moveEncoded);
        }
    }

    bool inCastlingSpot = false;
    char castlingRow = (colour ? 7 : 0);
    if ((i == castlingRow) && (j == 4)){
        inCastlingSpot = true;
    }

    bool canLongCastle = inCastlingSpot;
    if (canLongCastle && (board -> getPieceEnumAt(castlingRow, 0) == (colour ? 4 : 12))){
        for (char x : canlongcastlelist){
            canLongCastle &= (board -> getPieceEnumAt(i, x) == 0);
        }
        if (canLongCastle){
            std::array<char, 4> move = {i, j, i, 2};
            int moveEncoded = mv->encodeLongCastle(move);
            moves->push_back(moveEncoded);
        }
    }
    
    bool canShortCastle = inCastlingSpot;
    if (canShortCastle && (board -> getPieceEnumAt(castlingRow, 7) == (colour ? 4 : 12))){
        for (char x : canshortcastlelist){
            canShortCastle &= (board -> getPieceEnumAt(i, x) == 0);
        }
        if (canShortCastle){
            std::array<char, 4> move = {i, j, i, 6};
            int moveEncoded = mv->encodeShortCastle(move);
            moves->push_back(moveEncoded);
        }
    }

    return moves;
}; 