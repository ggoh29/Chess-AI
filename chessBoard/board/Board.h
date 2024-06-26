#ifndef BOARD_H
#define BOARD_H
#include "../pieces/Piece.h"
#include "../pieces/Pawn.h"
#include "../pieces/Knight.h"
#include "../pieces/Bishop.h"
#include "../pieces/Rook.h"
#include "../pieces/Queen.h"
#include "../pieces/King.h"
#include "../moves/Moves.h"
#include "./BoardRepr.h"
#include "BoardHash.h"
#include <stdio.h>
#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>


class Board{

    static Piece* b;

    static Pawn* wp;
    static Bishop* wb;
    static Knight* wkn;
    static Rook* wr;
    static Queen* wq;
    static King* wkg;

    static Pawn* bp;
    static Bishop* bb;
    static Knight* bkn;
    static Rook* br;
    static Queen* bq;
    static King* bkg;

    static char piecelist[16];
    static char charlist[8];
    static Piece* plist[16];
    static BoardHash* hash;

    BoardRepr* board;

    bool bkgHasMoved;
    bool br1HasMoved;
    bool br2HasMoved;
    bool wkgHasMoved;
    bool wr1HasMoved;
    bool wr2HasMoved;

    unsigned long hash_number;
    std::map<unsigned long, std::vector<int>*> move_map;

    public:

        Board();

        Board(std::array<Piece*, 64> chessBoard);

        Board(std::array<Piece*, 64> chessBoard,
        bool bkgHasMoved,
        bool br1HasMoved,
        bool br2HasMoved,
        bool wkgHasMoved,
        bool wr1HasMoved,
        bool wr2HasMoved
        );

        bool pieceTaken();
        unsigned long getHash();
        int pieceEnumAtLocation(int i, int j);
        int getCastlingState();
        void setCastlingState(int castlingState);
        bool isValidPosforKing(int i_king, int j_king, bool turn);
        std::vector<int>* getMoves(bool turn, int previousMove);
        void makeMove(bool turn, int move);
        void undoMove(bool turn, int undoMove, int castlingState);
        void printMove(int move);
        void printBoard();
};
#endif