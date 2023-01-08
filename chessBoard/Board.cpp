#include "Board.h"


Board::Board()
: chessBoard {{{br , bkn, bb , bq, bkg , bb , bkn, br }, 
               {bp , bp , bp , bp , bp , bp , bp , bp },
               {b  , b  , b  , b  , b  , b  , b  , b  },
               {b  , b  , b  , b  , b  , b  , b  , b  },
               {b  , b  , b  , b  , b  , b  , b  , b  },
               {b  , b  , b  , b  , b  , b  , b  , b  },
               {wp , wp , wp , wp , wp , wp , wp , wp },
               {wr , wkn, wb , wq, wkg , wb , wkn, wr }}},
bkgHasMoved{false},
br1HasMoved{false},
br2HasMoved{false},
wkgHasMoved{false},
wr1HasMoved{false},
wr2HasMoved{false}
{}

Board::Board(std::array<long,4> encoding)
: bkgHasMoved{false},
    br1HasMoved{false},
    br2HasMoved{false},
    wkgHasMoved{false},
    wr1HasMoved{false},
    wr2HasMoved{false}
{
    char mask = 15;
    for (int i = 7 ; i >= 0; i--){
        for (int j = 7; j >= 0 ; j--) {
            int encodedPiece = encoding[(i / 2)] & mask;
            chessBoard[i][j] = plist[encodedPiece];
            encoding[(i / 2)] = encoding[(i / 2)] >> 4;
        }
    }
}

Board::Board(std::array<long,4> encoding, 
bool bkgHasMoved,
bool br1HasMoved,
bool br2HasMoved,
bool wkgHasMoved,
bool wr1HasMoved,
bool wr2HasMoved
)
: bkgHasMoved{bkgHasMoved},
    br1HasMoved{br1HasMoved},
    br2HasMoved{br2HasMoved},
    wkgHasMoved{wkgHasMoved},
    wr1HasMoved{wr1HasMoved},
    wr2HasMoved{wr2HasMoved}
{
    char mask = 15;
    for (int i = 7 ; i >= 0; i--){
        for (int j = 7; j >= 0 ; j--) {
            int encodedPiece = encoding[(i / 2)] & mask;
            chessBoard[i][j] = plist[encodedPiece];
            encoding[(i / 2)] = encoding[(i / 2)] >> 4;
        }
    }
}

Board::Board(std::array<std::array<Piece*, 8>, 8> chessBoard)
: chessBoard {chessBoard},
bkgHasMoved{false},
br1HasMoved{false},
br2HasMoved{false},
wkgHasMoved{false},
wr1HasMoved{false},
wr2HasMoved{false}
{}

Board::Board(std::array<std::array<Piece*, 8>, 8> chessBoard,
bool bkgHasMoved,
bool br1HasMoved,
bool br2HasMoved,
bool wkgHasMoved,
bool wr1HasMoved,
bool wr2HasMoved
)
: chessBoard {chessBoard},
    bkgHasMoved{bkgHasMoved},
    br1HasMoved{br1HasMoved},
    br2HasMoved{br2HasMoved},
    wkgHasMoved{wkgHasMoved},
    wr1HasMoved{wr1HasMoved},
    wr2HasMoved{wr2HasMoved}
{}

Board::~Board() {
    delete &chessBoard;
    std::cout << "Deleted Board" << std::endl;
}

int Board::getHash(){
    int hash = 0;
    std::array<long,4> encoding = encodeBoard();
    for (int i = 0; i < 4; i++){
        hash = (hash + (324723947 + encoding[i])) ^ 93485734985;
    }
    return hash;
}

std::array<long,4> Board::encodeBoard(){
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
    std::cout << std::endl;

    return encoding;
};

std::vector<int>* Board::getMoves(bool turn, int previousMove){
    int mask = 8;
    std::vector<int>* finalArray = new std::vector<int>();
    for (int i = 0 ; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Piece* piece = chessBoard[i][j];
            int encoding = piece -> pieceEnum();
            if (((mask ^ encoding) >> 3) == turn){
                std::vector<int>* moves = piece -> getMoves(i, j, chessBoard, previousMove);
                finalArray->insert(finalArray->end(), moves->begin(), moves->end());
                delete moves;
            }
        }
    };
    // for (int l = 0; l < finalArray->size(); l++){
    //     std::cout << finalArray->at(l) << std::endl;;
    // } 
    // std::cout <<  finalArray->size() << std::endl;
    return finalArray;
};

void Board::printBoard(){
    std::cout << "\033c" << "  +---+---+---+---+---+---+---+---+" << std::endl;
    for (int i = 0 ; i < 8; i++) {
        std::cout << (8 - i) << " ";
        for (int j = 0; j < 8; j++) {
            std::cout << "|";
            Piece* piece = chessBoard[i][j];
            std::cout << " " << piece -> pieceAscii() << " ";
        }
        std::cout << "|" << std::endl << "  +---+---+---+---+---+---+---+---+" << std::endl;
    };
    std::cout << "    A   B   C   D   E   F   G   H" << std::endl;
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