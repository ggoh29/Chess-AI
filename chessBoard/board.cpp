#include "pieces/Piece.h"
#include "pieces/Pawn.h"
#include "pieces/Knight.h"
#include "pieces/Bishop.h"
#include "pieces/Rook.h"
#include "pieces/Queen.h"
#include "pieces/King.h"
#include <stdio.h>
#include <iostream>
#include <array>
#include <vector>
using namespace std;

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

    public:

        Board()
        : chessBoard {{{br , bkn, bb , bkg, bq , bb , bkn, br }, 
                       {bp , bp , bp , bp , bp , bp , bp , bp },
                       {b  , b  , b  , b  , b  , b  , b  , b  },
                       {b  , b  , b  , b  , b  , b  , b  , b  },
                       {b  , b  , b  , b  , b  , b  , b  , b  },
                       {b  , b  , b  , b  , b  , b  , b  , b  },
                       {wp , wp , wp , wp , wp , wp , wp , wp },
                       {wr , wkn, wb , wkg, wq , wb , wkn, wr }}}
        {}

        Board(std::array<long,4> encoding){
            char mask = 15;
            for (int i = 7 ; i >= 0; i--){
                for (int j = 7; j >= 0 ; j--) {
                    // Piece* piece = chessBoard[i][j];
                    // char e = piece -> pieceEnum();
                    int encodedPiece = encoding[(i / 2)] & mask;
                    chessBoard[i][j] = plist[encodedPiece];
                    encoding[(i / 2)] = encoding[(i / 2)] >> 4;
                }
            }
            }

        ~Board() {
            delete &chessBoard;
            cout << "Deleted Board" << endl;
        }

        std::array<long,4> encodeBoard(){
            long firstQuarter = 0;
            long secondQuarter = 0;
            long thirdQuarter = 0;
            long fourthQuarter = 0;
            std::array<long,4> encoding {firstQuarter, secondQuarter, thirdQuarter, fourthQuarter};
            for (int i = 0 ; i < 8; i++){
                for (int j = 0; j < 8; j++) {
                    Piece* piece = chessBoard[i][j];
                    char e = piece -> pieceEnum();
                    encoding[(i / 2)] = (encoding[(i / 2)] << 4) ^ e;
                }
            }
            cout << endl;

            return encoding;
        };

        std::vector<int> getMoves(){
            std::vector<int> finalArray;
            for (int i = 0 ; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    std::vector<int> moves = chessBoard[i][j] -> getMoves(i, j, chessBoard);
                    finalArray.insert(finalArray.end(), moves.begin(), moves.end());
                }
            };
            return finalArray;
        };

        void printBoard(){
            cout << endl << "  +---+---+---+---+---+---+---+---+" << endl;
            for (int i = 0 ; i < 8; i++) {
                cout << (8 - i) << " ";
                for (int j = 0; j < 8; j++) {
                    cout << "|";
                    Piece* piece = chessBoard[i][j];
                    cout << " " << piece -> pieceAscii() << " ";
                }
                cout << "|" << endl << "  +---+---+---+---+---+---+---+---+" << endl;
            };
            cout << "    A   B   C   D   E   F   G   H" << endl;
        };
};

Piece* Board::b = new Piece();

Pawn* Board::wp = new Pawn(1);
Bishop* Board::wb = new Bishop(1);
Knight* Board::wkn = new Knight(1);
Rook* Board::wr = new Rook(1);
Queen* Board::wq = new Queen(1);
King* Board::wkg = new King(1);

Pawn* Board::bp = new Pawn(0);
Bishop* Board::bb = new Bishop(0);
Knight* Board::bkn = new Knight(0);
Rook* Board::br = new Rook(0);
Queen* Board::bq = new Queen(0);
King* Board::bkg = new King(0);

Piece* Board::plist[16] = {b, wp, wb, wkn, wr, wq, wkg, b, 
                           b, bp, bb, bkn, br, bq, bkg, b};

int main(){
    Board* b = new Board();
    b->printBoard();
    std::array<long,4> encoding = b->encodeBoard();
    Board* b_new = new Board(encoding);
    b_new -> printBoard();
};  