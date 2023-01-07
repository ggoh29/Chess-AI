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
     {b  , b  , b  , b  , b  , b  , b  , b  }, 
     {b  , b  , b  , b  , b  , b  , b  , b  },
     {b  , b  , b  , b  , b  , b  , b  , b  },
     {b  , b  , b  , wp , bp , b  , b  , b  },
     {b  , b  , b  , b  , b  , b  , b  , b  },
     {b  , b  , b  , b  , b  , b  , b  , b  },
     {b  , b  , b  , b  , b  , b  , b  , b  },
     {b  , b  , b  , b  , b  , b  , b  , b  }
    }};
    Board* b = new Board(chessBoard);
    std::array<int, 4> move = {1, 4, 3, 4};
    int encodedMove = wp->encodeMove(move);
    std::vector<int>* moves = b->getMoves(1, encodedMove);
    std::cout << moves->size() << std::endl;
    return true;
};  