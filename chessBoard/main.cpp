#include "Board.h"

Piece* b = new Piece();

Pawn* wp = new Pawn(1);
Bishop* wb = new Bishop(1);
Knight* wkn = new Knight(1);
Rook* wr = new Rook(1);
Queen* wq = new Queen(1);
King* wkg = new King(1);

Pawn* bp = new Pawn(0);
Bishop* bb = new Bishop(0);
Knight* bkn = new Knight(0);
Rook* br = new Rook(0);
Queen* bq = new Queen(0);
King* bkg = new King(0);

int main(){
    std::array<std::array<Piece*, 8>, 8> chessBoard = {{
     {br , b  , b  , b  , bkg, b  , b  , br }, 
     {bp , b  , b  , b  , wp , b  , b  , bp },
     {wp , b  , b  , b  , b  , b  , b  , wp },
     {b  , b  , b  , b  , b  , b  , b  , b  },
     {b  , b  , b  , b  , b  , b  , b  , b  },
     {bp , b  , b  , b  , b  , b  , b  , bp },
     {wp , b  , b  , b  , bp , b  , b  , wp },
     {wr , b  , b  , b  , wkg, b  , b  , wr }
    }};
    Board* b = new Board(chessBoard);
    std::vector<int>* moves = b->getMoves(1, 0);
    int movesSize = moves->size();
    std::cout << "Testing: test returned " << movesSize << " moves." << std::endl;
    std::vector<int>* validMoves = b->getValidMoves(1, 0);
    int validMovesSize = validMoves->size();
    std::cout << "Testing: test returned " << validMovesSize << " valid moves." << std::endl;
};  