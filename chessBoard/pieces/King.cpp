#include "King.h"
#include <iostream>

King::King(bool colour):colour(colour),mv(new Move()){}

int King::pieceEnum(){
        return colour ? 6 : 14;
};

bool King::isSameTeam(bool colour, Piece* piece){
    if (piece->pieceEnum() == 0){
        return true;
    }
    int mask = 8;
    return ((((piece -> pieceEnum()) & mask) >> 3) != colour);
}

std::string King::pieceAscii(){
        return colour ? "♚" : "♔";
};


std::vector<int>* King::getMoves(int i, int j, std::array<std::array<Piece*, 8>, 8> chessBoard, int previousMove){
    std::vector<int> *moves = new std::vector<int>();
    int directions[8][2] = {{1, 0}, {1, 1}, {1, -1}, {0, 1}, {0, -1}, {-1, 0}, {-1, 1}, {-1, -1}};
    for (auto dir : directions){
        int x = i + dir[0];
        int y = j + dir[1];
        if (0 <= x && x < 8 && 0 <= y && y < 8 && ((chessBoard[x][y] -> pieceEnum()) == 0 || !isSameTeam(colour, chessBoard[x][y]))){
            std::array<int, 4> move = {i, j, x, y};
            int moveEncoded = mv->encodeMove(move);
            moves->push_back(moveEncoded);
        }
    }
    std::cout << i << " " << j << std::endl;
    bool inCastlingSpot = false;
    int castlingRow = colour ? 7 : 0;
    if ((i == castlingRow) && (j == 4)){
        inCastlingSpot = true;
    }

    bool canLongCastle = inCastlingSpot;
    if (canLongCastle && chessBoard[castlingRow][0]->pieceEnum() == colour ? 4 : 12){
        for (int x : {1, 2, 3}){
            canLongCastle &= chessBoard[i][x]->pieceEnum() == 0;
        }
    }
    if (canLongCastle){
        std::array<int, 4> move = {i, j, i, 2};
        int moveEncoded = mv->encodeLongCastle(move);
        moves->push_back(moveEncoded);
    }

    bool canShortCastle = inCastlingSpot;
    if (canShortCastle && chessBoard[castlingRow][7]->pieceEnum() == colour ? 4 : 12){
        for (int x : {5, 6}){
            canShortCastle &= chessBoard[i][x]->pieceEnum() == 0;
        }
    }
    if (canShortCastle){
        std::array<int, 4> move = {i, j, i, 6};
        int moveEncoded = mv->encodeShortCastle(move);
        moves->push_back(moveEncoded);
    }

    return moves;
}; 