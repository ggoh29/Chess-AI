#include "Board.h"


Board::Board() 
: Board(std::array<Piece*, 64> (
{br , bkn, bb , bq, bkg , bb , bkn, br , 
bp , bp , bp , bp , bp , bp , bp , bp ,
b  , b  , b  , b  , b  , b  , b  , b  ,
b  , b  , b  , b  , b  , b  , b  , b  ,
b  , b  , b  , b  , b  , b  , b  , b  ,
b  , b  , b  , b  , b  , b  , b  , b  ,
wp , wp , wp , wp , wp , wp , wp , wp ,
wr , wkn, wb , wq, wkg , wb , wkn, wr }))
{}

Board::Board(std::array<Piece*, 64> chessBoard) 
: Board(chessBoard, false, false, false, false, false, false)
{}

Board::Board(std::array<Piece*, 64> chessBoard,
bool bkgHasMoved,
bool br1HasMoved,
bool br2HasMoved,
bool wkgHasMoved,
bool wr1HasMoved,
bool wr2HasMoved
)
:  bkgHasMoved{bkgHasMoved},
    br1HasMoved{br1HasMoved},
    br2HasMoved{br2HasMoved},
    wkgHasMoved{wkgHasMoved},
    wr1HasMoved{wr1HasMoved},
    wr2HasMoved{wr2HasMoved}
{
std::array<int, 8> boardRepr = std::array<int, 8>({0, 0, 0, 0, 0, 0, 0, 0});
for (int i = 0 ; i < 8; i++){
    for (int j = 0; j < 8; j++) {
        Piece* piece = chessBoard[i * 8 + j];
        char e = piece -> pieceEnum();
        boardRepr[i] = boardRepr[i] ^ (e & 15) << (4 * j);
    }
}

this->board = new BoardRepr(boardRepr);
}

bool Board::pieceTaken(){
    int counter = 0;
    for (int i = 0; i < 8; i ++){
        for (int j = 0; j < 8; j++){
            if (this->board->getPieceEnumAt(i, j) != 0){
                counter ++;
            }
        }
    }
    return counter < 16;
}

unsigned long Board::getHash(){
    return hash->getHash(board);
}

int Board::pieceEnumAtLocation(int i, int j){
    return this->board->getPieceEnumAt(i, j);
};

int Board::getCastlingState(){
    return (bkgHasMoved << 5) + (br1HasMoved << 4) + (br2HasMoved << 3) + (wkgHasMoved << 2) + (wr1HasMoved << 1) + wr2HasMoved;
}

void Board::setCastlingState(int castlingState){
    bkgHasMoved = (castlingState >> 5) & 1;
    br1HasMoved = (castlingState >> 4) & 1;
    br2HasMoved = (castlingState >> 3) & 1;
    wkgHasMoved = (castlingState >> 2) & 1;
    wr1HasMoved = (castlingState >> 1) & 1;
    wr2HasMoved = castlingState & 1;
}

bool Board::isValidPosforKing(int i_king, int j_king, bool turn){
    if (i_king < 0 || i_king > 7 || j_king < 0 || j_king > 7){
        return false;
    }
    // No king and pawn check
    int directions1[8][2] = {{1, 0}, {1, 1}, {1, -1}, {0, 1}, {0, -1}, {-1, 0}, {-1, 1}, {-1, -1}};
    for (auto dir : directions1){
        int x = i_king + dir[0];
        int y = j_king + dir[1];
        if ((0 <= x) && (x < 8) && (0 <= y) && (y < 8)){
            int e = this->board->getPieceEnumAt(x, y);
            if (e == (turn ? 14 : 6)){
                return false;
            }
            int dr = (turn ? -1 : 1);
            if ((dir[0] == dr) && (dir[1] != 0) && (e == (turn ? 9 : 1))){
                return false;
            }
        }
    }
    // no knight check
    for (int x_dir : {-1, +1}){
        for (int y_dir : {-1, +1}){
            for (int x_mag : {1, 2}){
                for (int y_mag : {1, 2}){
                    int x = i_king + x_mag * x_dir;
                    int y = j_king + y_mag * y_dir;
                    if ((x_mag != y_mag) && (0 <= x) && (x < 8) && (0 <= y) && (y < 8) && (this->board->getPieceEnumAt(x, y) == (turn ? 11 : 3))){
                        return false;
                    }
                }
            }
        }
    }
    // no rook and queen check
    int directions2[4][2] = {{+1, 0}, {-1, 0}, {0, +1}, {0, -1}};
    for (auto direction : directions2){
        int xx = i_king + direction[0];
        int yy = j_king + direction[1];
        for (;(0 <= xx) && (xx < 8) && (0 <= yy) && (yy < 8);){
            int e = this->board->getPieceEnumAt(xx, yy);
            if ((e == (turn ? 12 : 4)) || (e == (turn ? 13 : 5))){
                return false;
            } else if (e != 0){
                break;
            }
            xx += direction[0];
            yy += direction[1];
        }
    }
    // no bishop and queen check
    for (int x = 0; x <= 1; x++){
        for (int y = 0; y <= 1; y++){
            int xx = x ? i_king + 1 : i_king - 1;
            int yy = y ? j_king + 1 : j_king - 1;
            while ((0 <= xx) && (xx < 8) && (0 <= yy) && (yy < 8)){
                int e = this->board->getPieceEnumAt(xx, yy);
                if ((e == (turn ? 10 : 2)) || (e == (turn ? 13 : 5))){
                    return false;
                } else if (e != 0) {
                    break;
                }
                xx = x ? xx + 1 : xx - 1;
                yy = y ? yy + 1 : yy - 1;
            }
        }
    }
    return true;
}

std::vector<int>* Board::getMoves(bool turn, int previousMove){
    int mask = 8;
    std::vector<int>* finalArray = new std::vector<int>();
    for (int i = 0 ; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int encoding = this->board->getPieceEnumAt(i, j);
            Piece* piece = this->plist[encoding];
            if (((mask ^ encoding) >> 3) == turn){
                std::vector<int>* moves = piece -> getMoves(i, j, board, previousMove);
                finalArray->insert(finalArray->end(), moves->begin(), moves->end());
                delete moves;
            }
        }
    };
    return finalArray;
};


void Board::makeMove(bool turn, int mv){
    Move moveDocoder = Move();
    std::array<int, 4> move = moveDocoder.decodeMove(mv);
    int king = (turn ? 7 : 0);
    if ((1 << 28) & mv){
        this->board->putPieceEnum(king, 2, this->board->getPieceEnumAt(king, 4));
        this->board->putPieceEnum(king, 3, this->board->getPieceEnumAt(king, 0));
        this->board->putPieceEnum(king, 4, 0);
        this->board->putPieceEnum(king, 0, 0);
        (turn ? wkgHasMoved : bkgHasMoved) = true;
        (turn ? wr1HasMoved : br1HasMoved) = true;
    } else if ((1 << 29) & mv){
        this->board->putPieceEnum(king, 6, this->board->getPieceEnumAt(king, 4));
        this->board->putPieceEnum(king, 5, this->board->getPieceEnumAt(king, 7));
        this->board->putPieceEnum(king, 4, 0);
        this->board->putPieceEnum(king, 7, 0);
        (turn ? wkgHasMoved : bkgHasMoved) = true;
        (turn ? wr2HasMoved : br2HasMoved) = true;
    } else if ((1 << 31) & mv){
        this->board->putPieceEnum(move[2], move[3], this->board->getPieceEnumAt(move[0], move[1]));
        this->board->putPieceEnum((move[2] + (turn ? 1 : -1)), move[3], 0);
        this->board->putPieceEnum(move[0], move[1], 0);
    } else if ((1 << 30) & mv){
        int piece = moveDocoder.decodePromotion(mv);
        this->board->putPieceEnum(move[2], move[3], piece);
        this->board->putPieceEnum(move[0], move[1], 0);
    } else {
        this->board->putPieceEnum(move[2], move[3], this->board->getPieceEnumAt(move[0], move[1]));
        this->board->putPieceEnum(move[0], move[1], 0);
    }
    if ((move[0] == (turn ? 7 : 0)  && move[1] == 0) || (move[2] == (turn ? 7 : 0) && move[3] == 0)){
        (turn ? wr1HasMoved : br1HasMoved) = true;
    }
    if ((move[0] == (turn ? 7 : 0)  && move[1] == 7) || (move[2] == (turn ? 7 : 0) && move[3] == 7)){
        (turn ? wr2HasMoved : br2HasMoved) = true;
    }
    if ((move[0] == (turn ? 7 : 0)  && move[1] == 4) || (move[2] == (turn ? 7 : 0) && move[3] == 4)){
        (turn ? wkgHasMoved : bkgHasMoved) = true;
    }
}

void Board::undoMove(bool turn, int undoMove, int castlingState){
    this->setCastlingState(castlingState);
    Move moveDocoder =  Move();
    int capturedPiece = (undoMove >> 16) & 0b1111;
    int king = (turn ? 7 : 0);
    std::array<int, 4> move = moveDocoder.decodeMove(undoMove);
    if ((1 << 28) & undoMove){
        this->board->putPieceEnum(king, 4, this->board->getPieceEnumAt(king, 2));
        this->board->putPieceEnum(king, 0, this->board->getPieceEnumAt(king, 3));
        this->board->putPieceEnum(king, 2, 0);
        this->board->putPieceEnum(king, 3, 0);
    } else if ((1 << 29) & undoMove){
        this->board->putPieceEnum(king, 4, this->board->getPieceEnumAt(king, 6));
        this->board->putPieceEnum(king, 7, this->board->getPieceEnumAt(king, 5));
        this->board->putPieceEnum(king, 6, 0);
        this->board->putPieceEnum(king, 5, 0);
    } else if ((1 << 31) & undoMove){
        this->board->putPieceEnum(move[0], move[1], this->board->getPieceEnumAt(move[2], move[3]));
        this->board->putPieceEnum((move[2] + (turn ? 1 : -1)), move[3], (turn ? 9 : 1));
        this->board->putPieceEnum(move[2], move[3], 0);
    } else if ((1 << 30) & undoMove){
        this->board->putPieceEnum(move[2], move[3], capturedPiece);
        this->board->putPieceEnum(move[0], move[1], turn ? 1 : 9);
    } else {
        this->board->putPieceEnum(move[0], move[1], this->board->getPieceEnumAt(move[2], move[3]));
        this->board->putPieceEnum(move[2], move[3], capturedPiece);
    }
}

void Board::printMove(int move){
    Move mvDecoder = Move();
    std::array<int, 4> mv = mvDecoder.decodeMove(move);
    if ((1 << 28) & move){
        std::cout << "O-O-O";
    } else if ((1 << 29) & move){
        std::cout << "O-O";
    } else if ((1 << 30) & move){
        int piece = mvDecoder.decodePromotion(move);
        std::cout << charlist[mv[1]] << 8 - mv[0] << "-" << charlist[mv[3]] << 8 - mv[2] << " " << piecelist[piece];
    } else {
        std::cout << charlist[mv[1]] << 8 - mv[0] << "-" << charlist[mv[3]] << 8 - mv[2];
    }
}

void Board::printBoard(){
    std::cout << "\033c";
    std::cout <<  "  +---+---+---+---+---+---+---+---+" << std::endl;
    for (int i = 0 ; i < 8; i++) {
        std::cout << (8 - i) << " ";
        for (int j = 0; j < 8; j++) {
            std::cout << "|";
            int piece = this->board->getPieceEnumAt(i, j);
            std::cout << " " << plist[piece] -> pieceAscii() << " ";
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

char Board::charlist[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
char Board::piecelist[16] = {' ', ' ', 'B', 'N', 'R', 'Q', 'K', ' ',
                             ' ', ' ', 'B', 'N', 'R', 'Q', 'K', ' '};

BoardHash* Board::hash = new BoardHash();