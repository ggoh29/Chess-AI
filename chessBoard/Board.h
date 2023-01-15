#ifndef BOARD_H
#define BOARD_H
#include "pieces/Piece.h"
#include "pieces/Pawn.h"
#include "pieces/Knight.h"
#include "pieces/Bishop.h"
#include "pieces/Rook.h"
#include "pieces/Queen.h"
#include "pieces/King.h"
#include  "moves/Moves.h"
#include <stdio.h>
#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <cstring>

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

    static Piece* plist[16];
    std::array<std::array<Piece*, 8>, 8> chessBoard;

    bool bkgHasMoved;
    bool br1HasMoved;
    bool br2HasMoved;
    bool wkgHasMoved;
    bool wr1HasMoved;
    bool wr2HasMoved;

    public:

        Board();

        Board(std::array<long,4> encoding);
        Board(std::string encoding);

        Board(std::array<long,4> encoding, 
        bool bkgHasMoved,
        bool br1HasMoved,
        bool br2HasMoved,
        bool wkgHasMoved,
        bool wr1HasMoved,
        bool wr2HasMoved
        );

        Board(std::array<std::array<Piece*, 8>, 8> chessBoard);

        Board(std::array<std::array<Piece*, 8>, 8> chessBoard,
        bool bkgHasMoved,
        bool br1HasMoved,
        bool br2HasMoved,
        bool wkgHasMoved,
        bool wr1HasMoved,
        bool wr2HasMoved
        );

        ~Board();
        int getHash();
        std::string getString();
        std::array<long,4> encodeBoard();
        bool isValidPosforKing(int i_king, int j_king, bool turn);
        std::vector<int>* getMoves(bool turn, int previousMove);
        std::vector<int>* getValidMoves(bool turn, int previousMove);
        Board* makeMove(bool turn, int move);
        void printBoard();
};
#endif