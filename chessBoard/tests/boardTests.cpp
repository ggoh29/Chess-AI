#include "../pieces/Piece.h"
#include "../pieces/Pawn.h"
#include "../pieces/Knight.h"
#include "../pieces/Bishop.h"
#include "../pieces/Rook.h"
#include "../pieces/Queen.h"
#include "../pieces/King.h"
#include "../Board.h"
#include <stdio.h>
#include <iostream>
#include <array>
#include <vector>
#include <cassert>

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

Piece* plist[16] = {b, wp, wb, wkn, wr, wq, wkg, b, 
                    b, bp, bb, bkn, br, bq, bkg, b};


void en_passant_works_as_intended(){
    std::cout << "Testing: en passant test returns 3 moves" << std::endl;
    std::array<std::array<Piece*, 8>, 8> chessBoard = {{
     {b  , b  , b  , b  , b  , b  , b  , b  }, 
     {b  , b  , b  , b  , b  , b  , b  , b  },
     {b  , b  , bp , b  , b  , b  , b  , b },
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
    int movesSize = moves->size();
    std::cout << "Testing: en passant test actually returned " << movesSize << " moves." << std::endl;
    assert (movesSize == 3);
}

void promotion_works_as_intended(){
    std::cout << "Testing: promotion tests returns 10 moves" << std::endl;
    std::array<std::array<Piece*, 8>, 8> chessBoard = {{
     {b  , b  , b  , bp , bp , bp , b  , b  }, 
     {b  , b  , b  , b  , wp , b  , b  , b  },
     {b  , b  , b  , b  , b  , b  , b  , b  },
     {b  , b  , b  , b  , b  , b  , b  , b  },
     {b  , b  , b  , b  , b  , b  , b  , b  },
     {b  , b  , b  , b  , b  , b  , b  , b  },
     {b  , b  , b  , b  , b  , b  , b  , b  },
     {b  , b  , b  , b  , b  , b  , b  , b  }
    }};
    Board* b = new Board(chessBoard);
    std::vector<int>* moves = b->getMoves(1, 0);
    int movesSize = moves->size();
    std::cout << "Testing: promotion tests actually returned " <<  movesSize << " moves" << std::endl;
    assert (movesSize == 10);
}



int main(){
    en_passant_works_as_intended();
    promotion_works_as_intended();
    return 0;
}