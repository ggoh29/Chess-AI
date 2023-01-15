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

Board::Board(std::string encoding){
    int mask = 15;
    char* a = new char[34];
    std::strcpy(a, encoding.c_str());
    for (int i = 0 ; i < 8; i++){
        for (int j = 0; j < 4; j++) {
            std::cout << (int) a[(i + j * 8) + 1] << std::endl;
            chessBoard[i][j * 2] =  plist[(int) a[(i + j * 8) + 1] & mask];
            chessBoard[i][j * 2 + 1] = plist[(int) (a[(i + j * 8) + 1]>>4) & mask];
        }
    }
    this->bkgHasMoved = (a[1] & (1 >> 5)) > 0;
    this->br1HasMoved = (a[1] & (1 >> 4)) > 0;
    this->br2HasMoved = (a[1] & (1 >> 3)) > 0;
    this->wkgHasMoved = (a[1] & (1 >> 2)) > 0;
    this->wr1HasMoved = (a[1] & (1 >> 1)) > 0;
    this->wr2HasMoved = (a[1] & (1)) > 0;
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

std::string Board::getString(){
    char s[33];
    for (int i = 0 ; i < 8; i++){
        for (int j = 0; j < 4; j++) {
            s[(i + j * 8) + 1] = ((chessBoard[i][j*2]->pieceEnum() & 15) << 4) + (chessBoard[i][j*2+1]->pieceEnum() & 15);
        }
    }
    s[0] = (bkgHasMoved << 5) + (br1HasMoved << 4) + (br2HasMoved << 3) + (wkgHasMoved << 2) + (wr1HasMoved << 1) + wr2HasMoved;
	std::string str = ""; 
	for (int x = 0; x < 33; x++) { 
		str = str + s[x]; 
	} 
    std::cout << str << std::endl;
    return str;
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

bool Board::isValidPosforKing(int i_king, int j_king, bool turn){
    if (i_king < 0 || i_king > 7 || j_king < 0 || j_king > 7){
        return false;
    }
    // No king and pawn check
    int directions1[8][2] = {{1, 0}, {1, 1}, {1, -1}, {0, 1}, {0, -1}, {-1, 0}, {-1, 1}, {-1, -1}};
    for (auto dir : directions1){
        int x = i_king + dir[0];
        int y = j_king + dir[1];
        if (0 <= x && x < 8 && 0 <= y && y < 8){
            if ((chessBoard[x][y] -> pieceEnum()) == (turn ? 14 : 6)){
                return false;
            }
            int dr = (turn ? -1 : 1);
            if (dir[0] == dr && dir[1] != 0 && ((chessBoard[x][y] -> pieceEnum()) == (turn ? 9 : 1))){
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
                    if (x_mag != y_mag && 0 <= x && x < 8 && 0 <= y && y < 8 && ((chessBoard[x][y] -> pieceEnum()) == (turn ? 11 : 3))){
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
        for (;0 <= xx && xx < 8 && 0 <= yy && yy < 8;){
            if ((chessBoard[xx][yy] -> pieceEnum()) == (turn ? 12 : 4) || (chessBoard[xx][yy] -> pieceEnum()) == (turn ? 13 : 5)){
                return false;
            } else if (chessBoard[i_king][j_king] -> pieceEnum() != 0){
                break;
            }
            xx += direction[0];
            yy += direction[1];
        }
    }
    // no bishop and queen check
    for (int x = 0; x <= 1; x ++){
        for (int y = 0; y <= 1; y++){
            int xx = x ? i_king + 1 : i_king - 1;
            int yy = y ? j_king + 1 : j_king - 1;
            while (0 <= xx && xx < 8 && 0 <= yy && yy < 8){
                if ((chessBoard[xx][yy] -> pieceEnum()) == (turn ? 10 : 2) || (chessBoard[xx][yy] -> pieceEnum()) == (turn ? 13 : 5)){
                    return false;
                } else if (chessBoard[i_king][j_king] -> pieceEnum() != 0) {
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
            Piece* piece = chessBoard[i][j];
            int encoding = piece -> pieceEnum();
            if (((mask ^ encoding) >> 3) == turn){
                std::vector<int>* moves = piece -> getMoves(i, j, chessBoard, previousMove);
                finalArray->insert(finalArray->end(), moves->begin(), moves->end());
                delete moves;
            }
        }
    };
    return finalArray;
};

std::vector<int>* Board::getValidMoves(bool turn, int previousMove){
    std::vector<int>*  moves = getMoves(turn, previousMove);
    int i_king, j_king;
    bool b = false;
    for (i_king = 0 ; i_king < 8; i_king++) {
        for (j_king = 0; j_king < 8; j_king++) {
            if (chessBoard[i_king][j_king]->pieceEnum() == (turn ?  6 : 14)){
                b = true;
                break;
            };
        }
        if (b){
            break;
        }
    }
    Move* moveDocoder = new Move();
    moves->erase(std::remove_if(moves->begin(), moves->end(), [this, turn, moveDocoder, i_king, j_king](int mv) {
        std::array<int, 4> move = moveDocoder->decodeMove(mv);
        // std::cout << move[0] << " " << move[1] << " " << move[2] << " " << move[3] << std::endl;
        bool del = false;
        if ((1 << 28) & mv){
            for (int col : {2, 3, 4}){
                del |= !this->isValidPosforKing(turn ? 7 : 0, col, turn);
                del |= !(turn ? this->wkgHasMoved : this->bkgHasMoved) && !(turn ? this->wr1HasMoved : this->br1HasMoved);
            }
        } else if ((1 << 29) & mv){
            for (int col : {4, 5, 6}){
                del |= !this->isValidPosforKing(turn ? 7 : 0, col, turn);
                del |= !(turn ? this->wkgHasMoved : this->bkgHasMoved) && !(turn ? this->wr2HasMoved : this->br2HasMoved);
            }
        } else {
            Board* b = makeMove(turn, mv);
            if (chessBoard[i_king][j_king] -> pieceEnum() != b->chessBoard[i_king][j_king]->pieceEnum()){
                int i_king1, j_king1;
                bool done = false;
                for (i_king1 = 0 ; i_king1 < 8; i_king1++) {
                    for (j_king1 = 0; j_king1 < 8; j_king1++) {
                        if (b->chessBoard[i_king1][j_king1]->pieceEnum() == (turn ?  6 : 14)){
                            done = true;
                            break;
                        };
                    }
                    if (done){
                        break;
                    }
                }
                del |= !b->isValidPosforKing(i_king1, j_king1, turn);
            } else {
                del |= !b->isValidPosforKing(i_king, j_king, turn);
            }
        }
        return del;
    }), moves->end());
    delete moveDocoder;
    return moves;
};

Board* Board::makeMove(bool turn, int mv){
    Board* b = new Board(chessBoard, bkgHasMoved, br1HasMoved, br2HasMoved, wkgHasMoved, wr1HasMoved, wr2HasMoved);
    Move* moveDocoder = new Move();
    std::array<int, 4> move = moveDocoder->decodeMove(mv);
    if ((1 << 28) & mv){
        b->chessBoard[turn ? 7 : 0][2] = b->chessBoard[turn ? 7 : 0][4];
        b->chessBoard[turn ? 7 : 0][3] = b->chessBoard[turn ? 7 : 0][0];
        b->chessBoard[turn ? 7 : 0][4] = b->chessBoard[turn ? 7 : 0][0] = b->plist[0];
        turn ? b->wkgHasMoved : b->bkgHasMoved = true;
        turn ? b->wr1HasMoved : b->br1HasMoved = true;
    } else if ((1 << 29) & mv){
        b->chessBoard[turn ? 7 : 0][6] = b->chessBoard[turn ? 7 : 0][4];
        b->chessBoard[turn ? 7 : 0][5] = b->chessBoard[turn ? 7 : 0][0];
        b->chessBoard[turn ? 7 : 0][6] = b->chessBoard[turn ? 7 : 0][5] = b->plist[0];
        turn ? b->wkgHasMoved : b->bkgHasMoved = true;
        turn ? b->wr2HasMoved : b->br2HasMoved = true;
    } else if ((1 << 30) & mv){
        b->chessBoard[move[2]][move[3]] = b->chessBoard[move[0]][move[1]];
        b->chessBoard[move[2] + turn ? 1 : -1][move[3]] = b->plist[0];
        b->chessBoard[move[0]][move[1]] = b->plist[0];
    } else if ((1 << 31) & mv){
        int piece = moveDocoder->decodePromotion(mv);
        b->chessBoard[move[2]][move[3]] = b->plist[piece];
        b->chessBoard[move[0]][move[1]] = b->plist[0];
    } else {
        b->chessBoard[move[2]][move[3]] = b->chessBoard[move[0]][move[1]];
        b->chessBoard[move[0]][move[1]] = b->plist[0];
    }
    if ((move[0] == (turn ? 7 : 0)  && move[1] == 0) || (move[2] == (turn ? 7 : 0) && move[3] == 0)){
        turn ? b->wr1HasMoved : b->br1HasMoved = true;
    }
        if ((move[0] == (turn ? 7 : 0)  && move[1] == 7) || (move[2] == (turn ? 7 : 0) && move[3] == 7)){
        turn ? b->wr2HasMoved : b->br2HasMoved = true;
    }
    return b;
}

void Board::printBoard(){
    //std::cout << "\033c";
    std::cout <<  "  +---+---+---+---+---+---+---+---+" << std::endl;
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