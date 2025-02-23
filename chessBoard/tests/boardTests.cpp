#include "../pieces/Piece.h"
#include "../pieces/Pawn.h"
#include "../pieces/Knight.h"
#include "../pieces/Bishop.h"
#include "../pieces/Rook.h"
#include "../pieces/Queen.h"
#include "../pieces/King.h"
#include "../moves/Moves.h"
#include "../board/Board.h"
#include "../board/BoardHash.h"
#include "../board/BoardInterface.h"
#include "../board/BoardRepr.h"
#include <stdio.h>
#include <iostream>
#include <array>
#include <vector>
#include <cassert>
#include <string>
#include <unordered_set>
#include <map>

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


void en_passant_works_as_intended(std::string test, int mvs){
    std::cout << "Testing: " << test << " test returns "<< mvs << " moves" << std::endl;
    Move* mover = new Move();
    std::array<Piece*, 64> chessBoard = {{
     b  , b  , b  , b  , b  , b  , b  , b  , 
     b  , b  , b  , b  , b  , b  , b  , b  ,
     b  , b  , bp , b  , b  , b  , b  , b  ,
     b  , b  , b  , wp , bp , b  , b  , b  ,
     b  , b  , b  , b  , b  , b  , b  , b  ,
     b  , b  , b  , b  , b  , b  , b  , b  ,
     b  , b  , b  , b  , b  , b  , b  , b  ,
     b  , b  , b  , b  , b  , b  , b  , b  
    }};
    Board* b = new Board(chessBoard);
    std::array<int, 4> move = {1, 4, 3, 4};
    int encodedMove = mover->encodeMove(move);
    std::vector<int>* moves = b->getMoves(1, encodedMove);
    int movesSize = moves->size();
    std::cout << "Testing: " << test << " test actually returned " << movesSize << " moves." << std::endl;
    assert (movesSize == mvs);
}

void promotion_works_as_intended(std::string test, int mvs){
    std::cout << "Testing: " << test << " test returns "<< mvs << " moves" << std::endl;
    std::array<Piece*, 64> chessBoard = {{
     b  , b  , b  , bp , b ,  bp , b  , b  , 
     b  , b  , b  , b  , wp , b  , b  , b  ,
     b  , b  , b  , b  , b  , b  , b  , b  ,
     b  , b  , b  , b  , b  , b  , b  , b  ,
     b  , b  , b  , b  , b  , b  , b  , b  ,
     b  , b  , b  , b  , b  , b  , b  , b  ,
     b  , b  , b  , b  , b  , b  , b  , b  ,
     b  , b  , b  , b  , b  , b  , b  , b  
    }};
    Board* b = new Board(chessBoard);
    std::vector<int>* moves = b->getMoves(1, 0);
    int movesSize = moves->size();
    std::cout << "Testing: " << test << " test actually returned " << movesSize << " moves." << std::endl;
    assert (movesSize == mvs);
}

void pawn_moves_white_works_as_intended(std::string test, int mvs){
    std::cout << "Testing: " << test << " test returns "<< mvs << " moves" << std::endl;
    std::array<Piece*, 64> chessBoard = {{
     b  , b  , b  , bp , b ,  b  , b  , b  , 
     b  , b  , b  , b  , wp , b  , b  , b  ,
     b  , bp , bp , b  , b  , b  , b  , b  ,
     b  , wp , b  , b  , b  , b  , b  , b  ,
     b  , b  , b  , b  , b  , b  , b  , b  ,
     b  , b  , b  , b  , bp , b  , b  , b  ,
     b  , b  , b  , wp , b  , b  , b  , b  ,
     b  , b  , b  , b  , b  , b  , b  , b  
    }};
    Board* b = new Board(chessBoard);
    std::vector<int>* moves = b->getMoves(1, 0);
    int movesSize = moves->size();
    std::cout << "Testing: " << test << " test actually returned " << movesSize << " moves." << std::endl;
    assert (movesSize == mvs);
}

void pawn_moves_black_works_as_intended(std::string test, int mvs){
    std::cout << "Testing: " << test << " test returns "<< mvs << " moves" << std::endl;
    std::array<Piece*, 64> chessBoard = {{
     b  , b  , b  , b  , b  , b  , b  , b  , 
     b  , b  , b  , bp , b  , b  , b  , b  ,
     b  , bp , bp , b  , wp , b  , b  , b  ,
     b  , wp , b  , b  , b  , b  , b  , b  ,
     b  , b  , b  , b  , b  , b  , b  , b  ,
     b  , b  , b  , b  , bp , b  , b  , b  ,
     b  , b  , bp , wp , b  , b  , b  , b  ,
     b  , b  , b  , b  , b  , b  , b  , b  
    }};
    Board* b = new Board(chessBoard);
    std::vector<int>* moves = b->getMoves(0, 0);
    int movesSize = moves->size();
    std::cout << "Testing: " << test << " test actually returned " << movesSize << " moves." << std::endl;
    assert (movesSize == mvs);
}

void knight_moves_white_works_as_intended(std::string test, int mvs){
    std::cout << "Testing: " << test << " test returns "<< mvs << " moves" << std::endl;
    std::array<Piece*, 64> chessBoard = {{
     b  , b  , b  , b  , b  , b  , b  , b  , 
     b  , b  , b  , wkn, b  , bp , b  , b  ,
     b  , bp , b  , b  , b  , wp , b  , b  ,
     b  , wp , b  , b  , b  , b  , b  , b  ,
     b  , b  , b  , b  , b  , b  , b  , b  ,
     b  , b  , b  , b  , b  , b  , b  , b  ,
     b  , b  , b  , b  , b  , b  , b  , b  ,
     b  , b  , b  , b  , b  , b  , b  , b  
    }};
    Board* b = new Board(chessBoard);
    std::vector<int>* moves = b->getMoves(1, 0);
    int movesSize = moves->size();
    std::cout << "Testing: " << test << " test actually returned " << movesSize << " moves." << std::endl;
    assert (movesSize == mvs);
}

void knight_moves_black_works_as_intended(std::string test, int mvs){
    std::cout << "Testing: " << test << " test returns "<< mvs << " moves" << std::endl;
    std::array<Piece*, 64> chessBoard = {{
     b  , b  , b  , b  , b  , b  , b  , b  , 
     b  , b  , b  , bkn, b  , bp , b  , b  ,
     b  , bp , b  , b  , b  , wp , b  , b  ,
     b  , wp , b  , b  , b  , b  , b  , b  ,
     b  , b  , b  , b  , b  , b  , b  , b  ,
     b  , b  , b  , b  , b  , b  , b  , b  ,
     b  , b  , b  , b  , b  , b  , b  , b  ,
     b  , b  , b  , b  , b  , b  , b  , b  
    }};
    Board* b = new Board(chessBoard);
    std::vector<int>* moves = b->getMoves(0, 0);
    int movesSize = moves->size();
    std::cout << "Testing: " << test << " test actually returned " << movesSize << " moves." << std::endl;
    assert (movesSize == mvs);
}

void bishop_moves_white_works_as_intended(std::string test, int mvs){
    std::cout << "Testing: " << test << " test returns "<< mvs << " moves" << std::endl;
    std::array<Piece*, 64> chessBoard = {{
     b  , b  , b  , b  , b  , b  , b  , b  , 
     b  , b  , b  , bb , b  , bp , b  , b  ,
     b  , b  , b  , b  , b  , wp , b  , b  ,
     b  , bp , b  , b  , b  , wb , b  , b  ,
     b  , wp , b  , bp , b  , b  , b  , b  ,
     b  , b  , b  , wp , b  , b  , b  , b  ,
     b  , b  , b  , b  , b  , b  , b  , b  ,
     b  , b  , b  , b  , b  , b  , b  , b  
    }};
    Board* b = new Board(chessBoard);
    std::vector<int>* moves = b->getMoves(1, 0);
    int movesSize = moves->size();
    std::cout << "Testing: " << test << " test actually returned " << movesSize << " moves." << std::endl;
    assert (movesSize == mvs);
}

void bishop_moves_black_works_as_intended(std::string test, int mvs){
    std::cout << "Testing: " << test << " test returns "<< mvs << " moves" << std::endl;
    std::array<Piece*, 64> chessBoard = {{
     b  , b  , b  , b  , b  , b  , b  , b  , 
     b  , b  , b  , bb , b  , bp , b  , b  ,
     b  , b  , b  , b  , b  , wp , b  , b  ,
     b  , bp , b  , b  , b  , wb , b  , b  ,
     b  , wp , b  , bp , b  , b  , b  , b  ,
     b  , b  , b  , wp , b  , b  , b  , b  ,
     b  , b  , b  , b  , b  , b  , b  , b  ,
     b  , b  , b  , b  , b  , b  , b  , b  
    }};
    Board* b = new Board(chessBoard);
    std::vector<int>* moves = b->getMoves(0, 0);
    int movesSize = moves->size();
    std::cout << "Testing: " << test << " test actually returned " << movesSize << " moves." << std::endl;
    assert (movesSize == mvs);
}

void rook_moves_white_works_as_intended(std::string test, int mvs){
    std::cout << "Testing: " << test << " test returns "<< mvs << " moves" << std::endl;
    std::array<Piece*, 64> chessBoard = {{
     br , b  , b  , b  , b  , b  , b  , br , 
     b  , b  , b  , b  , b  , b  , b  , b  ,
     b  , b  , wr , b  , b  , b  , b  , b  ,
     bp , b  , b  , b  , b  , b  , b  , b  ,
     wp , b  , b  , b  , b  , b  , b  , b  ,
     b  , b  , b  , b  , b  , br , b  , b  ,
     b  , b  , b  , b  , b  , b  , b  , b  ,
     wr , b  , b  , b  , b  , b  , b  , wr 
    }};
    Board* b = new Board(chessBoard);
    std::vector<int>* moves = b->getMoves(1, 0);
    int movesSize = moves->size();
    std::cout << "Testing: " << test << " test actually returned " << movesSize << " moves." << std::endl;
    assert (movesSize == mvs);
}

void rook_moves_black_works_as_intended(std::string test, int mvs){
    std::cout << "Testing: " << test << " test returns "<< mvs << " moves" << std::endl;
    std::array<Piece*, 64> chessBoard = {{
     br , b  , b  , b  , b  , b  , b  , br , 
     b  , b  , b  , b  , b  , b  , b  , b  ,
     b  , b  , wr , b  , b  , b  , b  , b  ,
     bp , b  , b  , b  , b  , b  , b  , b  ,
     wp , b  , b  , b  , b  , b  , b  , b  ,
     b  , b  , b  , b  , b  , br , b  , b  ,
     b  , b  , b  , b  , b  , b  , b  , b  ,
     wr , b  , b  , b  , b  , b  , b  , wr 
    }};
    Board* b = new Board(chessBoard);
    std::vector<int>* moves = b->getMoves(0, 0);
    int movesSize = moves->size();
    std::cout << "Testing: " << test << " test actually returned " << movesSize << " moves." << std::endl;
    assert (movesSize == mvs);
}

void queen_moves_white_works_as_intended(std::string test, int mvs){
    std::cout << "Testing: " << test << " test returns "<< mvs << " moves" << std::endl;
    std::array<Piece*, 64> chessBoard = {{
     b  , b  , b  , b  , b  , b  , b  , b  , 
     b  , b  , b  , b  , bp , b  , b  , bp ,
     b  , b  , b  , b  , wp , b  , b  , wp ,
     b  , b  , b  , wq , b  , b  , b  , b  ,
     b  , b  , b  , b  , bq , b  , b  , b  ,
     bp , b  , b  , bp , b  , b  , b  , b  ,
     wp , b  , b  , wp , b  , b  , b  , b  ,
     b  , b  , b  , b  , b  , b  , b  , b  
    }};
    Board* b = new Board(chessBoard);
    std::vector<int>* moves = b->getMoves(1, 0);
    int movesSize = moves->size();
    std::cout << "Testing: " << test << " test actually returned " << movesSize << " moves." << std::endl;
    assert (movesSize == mvs);
}

void queen_moves_black_works_as_intended(std::string test, int mvs){
    std::cout << "Testing: " << test << " test returns "<< mvs << " moves" << std::endl;
    std::array<Piece*, 64> chessBoard = {{
     b  , b  , b  , b  , b  , b  , b  , b  , 
     b  , b  , b  , b  , bp , b  , b  , bp ,
     b  , b  , b  , b  , wp , b  , b  , wp ,
     b  , b  , b  , wq , b  , b  , b  , b  ,
     b  , b  , b  , b  , bq , b  , b  , b  ,
     bp , b  , b  , bp , b  , b  , b  , b  ,
     wp , b  , b  , wp , b  , b  , b  , b  ,
     b  , b  , b  , b  , b  , b  , b  , b  
    }};
    Board* b = new Board(chessBoard);
    std::vector<int>* moves = b->getMoves(0, 0);
    int movesSize = moves->size();
    std::cout << "Testing: " << test << " test actually returned " << movesSize << " moves." << std::endl;
    assert (movesSize == mvs);
}

void king_moves_white_works_as_intended(std::string test, int mvs){
    std::cout << "Testing: " << test << " test returns "<< mvs << " moves" << std::endl;
    std::array<Piece*, 64> chessBoard = {{
     br , b  , b  , b  , bkg, b  , b  , br , 
     bp , b  , b  , b  , b  , b  , b  , bp ,
     wp , b  , b  , b  , b  , b  , b  , wp ,
     b  , b  , b  , b  , b  , b  , b  , b  ,
     b  , b  , b  , b  , b  , b  , b  , b  ,
     bp , b  , b  , b  , b  , b  , b  , bp ,
     wp , b  , b  , b  , b  , b  , b  , wp ,
     wr , b  , b  , b  , wkg, b  , b  , wr 
    }};
    Board* b = new Board(chessBoard);
    std::vector<int>* moves = b->getMoves(1, 0);
    int movesSize = moves->size();
    std::cout << "Testing: " << test << " test actually returned " << movesSize << " moves." << std::endl;
    assert (movesSize == mvs);
}

void king_moves_black_works_as_intended(std::string test, int mvs){
    std::cout << "Testing: " << test << " test returns "<< mvs << " moves" << std::endl;
    std::array<Piece*, 64> chessBoard = {{
     br , b  , b  , b  , bkg, b  , b  , br , 
     bp , b  , b  , b  , b  , b  , b  , bp ,
     wp , b  , b  , b  , b  , b  , b  , wp ,
     b  , b  , b  , b  , b  , b  , b  , b  ,
     b  , b  , b  , b  , b  , b  , b  , b  ,
     bp , b  , b  , b  , b  , b  , b  , bp ,
     wp , b  , b  , b  , b  , b  , b  , wp ,
     wr , b  , b  , b  , wkg, b  , b  , wr 
    }};
    Board* b = new Board(chessBoard);
    std::vector<int>* moves = b->getMoves(0, 0);
    int movesSize = moves->size();
    std::cout << "Testing: " << test << " test actually returned " << movesSize << " moves." << std::endl;
    assert (movesSize == mvs);
}

void castle_white_not_valid_test1(std::string test, int mvs){
    std::cout << "Testing: " << test << " test returns "<< mvs << " moves" << std::endl;
    BoardInterface* interface = new BoardInterface();
    std::array<Piece*, 64> chessBoard = {{
     br , b  , b  , b  , bkg, b  , b  , br , 
     bp , b  , b  , b  , wp , b  , b  , bp ,
     wp , b  , b  , b  , b  , b  , b  , wp ,
     b  , b  , b  , b  , b  , b  , b  , b  ,
     b  , b  , b  , b  , b  , b  , b  , b  ,
     bp , b  , b  , b  , b  , b  , b  , bp ,
     wp , b  , b  , b  , bp , b  , b  , wp ,
     wr , b  , b  , b  , wkg, b  , b  , wr 
    }};
    Board* b = new Board(chessBoard);
    interface->setBoard(b);
    std::vector<int>* moves = interface->getMoves(1);
    int movesSize = moves->size();
    std::cout << "Testing: " << test << " test returned " << movesSize << " moves." << std::endl;
    std::vector<int>* validMoves = interface->getValidMoves(1);
    int validMovesSize = validMoves->size();
    std::cout << "Testing: " << test << " test returned " << validMovesSize << " valid moves." << std::endl;
    assert (movesSize == mvs);
    assert (validMovesSize == mvs - 4);
}

void castle_black_not_valid_test1(std::string test, int mvs){
    std::cout << "Testing: " << test << " test returns "<< mvs << " moves" << std::endl;
    BoardInterface* interface = new BoardInterface();
    std::array<Piece*, 64> chessBoard = {{
     br , b  , b  , b  , bkg, b  , b  , br , 
     bp , b  , b  , b  , wp , b  , b  , bp ,
     wp , b  , b  , b  , b  , b  , b  , wp ,
     b  , b  , b  , b  , b  , b  , b  , b  ,
     b  , b  , b  , b  , b  , b  , b  , b  ,
     bp , b  , b  , b  , b  , b  , b  , bp ,
     wp , b  , b  , b  , bp , b  , b  , wp ,
     wr , b  , b  , b  , wkg, b  , b  , wr 
    }};
    Board* b = new Board(chessBoard);
    interface->setBoard(b);
    std::vector<int>* moves = interface->getMoves(0);
    int movesSize = moves->size();
    std::cout << "Testing: " << test << " test returned " << movesSize << " moves." << std::endl;
    std::vector<int>* validMoves = interface->getValidMoves(0);
    int validMovesSize = validMoves->size();
    std::cout << "Testing: " << test << " test returned " << validMovesSize << " valid moves." << std::endl;
    assert (movesSize == mvs);
    assert (validMovesSize == mvs - 4);
}

void king_in_checkmate_no_moves(std::string test, int mvs){
    std::cout << "Testing: " << test << " test returns "<< mvs << " moves" << std::endl;
    BoardInterface* interface = new BoardInterface();
    std::array<Piece*, 64> chessBoard = {{
        br , bkn, bb , bq, bkg , bb , b  , br , 
        bp , bp , bp , bp , b  , wq , bp , bp ,
        b  , b  , b  , b  , b  , bkn, b  , b  ,
        b  , b  , b  , b  , bp , b  , b  , b  ,
        b  , b  , wb , b  , b  , b  , b  , b  ,
        b  , b  , b  , b  , b  , b  , b  , b  ,
        wp , wp , wp , wp , wp , wp , wp , wp ,
        wr , wkn, wb , wq, wkg , wb , wkn, wr 
    }};
    Board* b = new Board(chessBoard);
    interface->setBoard(b);
    std::vector<int>* moves = interface->getMoves(0);
    int movesSize = moves->size();
    std::cout << "Testing: " << test << " test returned " << movesSize << " moves." << std::endl;
    std::vector<int>* validMoves = interface->getValidMoves(0);
    int validMovesSize = 0;
    if (!validMoves->empty()){
        validMovesSize = validMoves->size();
    }
    std::cout << "Testing: " << test << " test returned " << validMovesSize << " valid moves." << std::endl;
    assert (validMovesSize == mvs);
}

void king_in_check_moves_correctly(std::string test, int mvs){
    std::cout << "Testing: " << test << " test returns "<< mvs << " moves" << std::endl;
    BoardInterface* interface = new BoardInterface();
    std::array<Piece*, 64> chessBoard = {{
        br , bkn, bb , bq, bkg , bb , b  , br , 
        bp , bp , bp , bp , b  , b  , bp , bp ,
        b  , b  , b  , b  , b  , bkn, b  , b  ,
        b  , b  , b  , b  , bp , b  , b  , wq ,
        b  , b  , wb , b  , b  , b  , b  , b  ,
        b  , b  , b  , b  , b  , b  , b  , b  ,
        wp , wp , wp , wp , wp , wp , wp , wp ,
        wr , wkn, wb , wq, wkg , wb , wkn, wr 
    }};
    Board* b = new Board(chessBoard);
    interface->setBoard(b);
    std::vector<int>* moves = interface->getMoves(0);
    int movesSize = moves->size();
    std::cout << "Testing: " << test << " test returned " << movesSize << " moves." << std::endl;
    std::vector<int>* validMoves = interface->getValidMoves(0);
    int validMovesSize = 0;
    if (!validMoves->empty()){
        validMovesSize = validMoves->size();
    }
    std::cout << "Testing: " << test << " test returned " << validMovesSize << " valid moves." << std::endl;
    assert (validMovesSize == mvs);
}

void king_in_check_moves_correctly2(std::string test, int mvs){
    std::cout << "Testing: " << test << " test returns "<< mvs << " moves" << std::endl;
    BoardInterface* interface = new BoardInterface();
    std::array<Piece*, 64> chessBoard = {{
        br , bkn, bb , b , bkg , bb , b  , br , 
        bp , bp , bp , bp , b  , bp , bp , bp ,
        b  , b  , b  , b  , b  , b  , b  , b  ,
        b  , b  , b  , b  , bp , b  , b  , b  ,
        b  , b  , b  , b  , b  , b  , b  , bq ,
        b  , b  , b  , b  , b  , wp , b  , b  ,
        wp , wp , wp , wp , wp , b  , wp , b  ,
        wr , wkn, wb , wq, wkg , wb , wkn, wr 
    }};
    Board* b = new Board(chessBoard);
    interface->setBoard(b);
    std::vector<int>* moves = interface->getMoves(1);
    int movesSize = moves->size();
    std::cout << "Testing: " << test << " test returned " << movesSize << " moves." << std::endl;
    std::vector<int>* validMoves = interface->getValidMoves(1);
    int validMovesSize = 0;
    if (!validMoves->empty()){
        validMovesSize = validMoves->size();
    }
    std::cout << "Testing: " << test << " test returned " << validMovesSize << " valid moves." << std::endl;
    assert (validMovesSize == mvs);
}

void king_in_pin_moves_correctly(std::string test, int mvs){
    std::cout << "Testing: " << test << " test returns "<< mvs << " moves" << std::endl;
    BoardInterface* interface = new BoardInterface();
    std::array<Piece*, 64> chessBoard = {{
        br , bkn, bb , bq, bkg , bb , bkn, br , 
        bp , bp , bp , bp , b  , bp , bp , bp ,
        b  , b  , b  , b  , b  , b  , b  , b  ,
        b  , b  , b  , b  , bp , b  , b  , wq ,
        b  , b  , wb , b  , b  , b  , b  , b  ,
        b  , b  , b  , b  , b  , b  , b  , b  ,
        wp , wp , wp , wp , wp , wp , wp , wp ,
        wr , wkn, wb , wq, wkg , wb , wkn, wr 
    }};
    Board* b = new Board(chessBoard);
    interface->setBoard(b);
    std::vector<int>* moves = interface->getMoves(0);
    int movesSize = moves->size();
    std::cout << "Testing: " << test << " test returned " << movesSize << " moves." << std::endl;
    std::vector<int>* validMoves = interface->getValidMoves(0);
    int validMovesSize = 0;
    if (!validMoves->empty()){
        validMovesSize = validMoves->size();
    }
    std::cout << "Testing: " << test << " test returned " << validMovesSize << " valid moves." << std::endl;
    assert (validMovesSize == mvs);
}

std::unordered_set<unsigned long>* getMovesAtDepthN(BoardInterface* interface, bool turn, int depth, int previousMove){
    std::unordered_set<unsigned long>* results = new std::unordered_set<unsigned long>();
    if (depth == 0){
        return new std::unordered_set<unsigned long>({interface->getHash()});
    } else {
        std::vector<int>* validMoves = interface->getValidMoves(turn);
        for (auto validMove : *validMoves){
            interface->makeMove(turn, validMove);
            std::unordered_set<unsigned long>* s = getMovesAtDepthN(interface, !turn, depth-1, validMove);
            results->insert(s->begin(), s->end());
            interface->undoMove(turn);
            delete s;
        }
        delete validMoves;
    }
    return results;
}

void correct_number_of_starting_moves_at_depth_n_test(int n, int size){
    std::cout << "Testing: correct number of moves at depth " << n  << " return " << size << " moves." << std::endl;
    BoardInterface* interface = new BoardInterface();
    std::unordered_set<unsigned long>* noOfMoves = getMovesAtDepthN(interface, 1, n, 0);
    int actualSize = noOfMoves->size();
    std::cout << "Testing: correct number of moves at depth " << n  << " returned " << actualSize << " moves." << std::endl;
    assert (actualSize == size);
}

int getMovesAtDepth(BoardInterface* interface, bool turn, int depth, int previousMove){
    int results = 0;
    std::vector<int>* validMoves = interface->getValidMoves(turn);
    if (depth == 1){
        return validMoves->size();
    }
    for (auto validMove : *validMoves){
        interface->makeMove(turn, validMove);
        int t = getMovesAtDepth(interface, !turn, depth-1, validMove);
        results += t;
        interface->undoMove(turn);
    }
    delete validMoves;
    return results;
}

void correct_number_of_starting_moves_at_depth_n_test_all(int n, int size){
    std::cout << "Testing: correct number of moves at depth " << n  << " return " << size << " moves." << std::endl;
    BoardInterface* interface = new BoardInterface();
    int actualSize = getMovesAtDepth(interface, 1, n, 0);
    std::cout << "Testing: correct number of moves at depth " << n  << " returned " << actualSize << " moves." << std::endl;
    assert (actualSize == size);
}

void correct_number_of_starting_moves_at_depth_n_test_all_fixed_pos_1(int n, int size, bool turn){
    std::cout << "Testing: correct number of moves at depth " << n  << " return " << size << " moves." << std::endl;
    BoardInterface* interface = new BoardInterface();
    std::array<Piece*, 64> chessBoard = {{
        br , bkn, bb , bq,  b  , bkg, b  , br , 
        bp , bp , b  , wp , bb , bp , bp , bp ,
        b  , b  , bp , b  , b  , b  , b  , b  ,
        b  , b  , b  , b  , b  , b  , b  , b  ,
        b  , b  , wb , b  , b  , b  , b  , b  ,
        b  , b  , b  , b  , b  , b  , b  , b  ,
        wp , wp , wp , b  , wkn, bkn, wp , wp ,
        wr , wkn, wb , wq, wkg , b  , b  , wr 
    }};
    Board* b = new Board(chessBoard);
    interface->setBoard(b);
    int actualSize = getMovesAtDepth(interface, turn, n, 0);
    std::cout << "Testing: correct number of moves at depth " << n  << " returned " << actualSize << " moves." << std::endl;
    assert (actualSize == size);
}

void correct_number_of_starting_moves_at_depth_n_test_all_fixed_pos_2(int n, int size, bool turn){
    std::cout << "Testing: correct number of moves at depth " << n  << " return " << size << " moves." << std::endl;
    BoardInterface* interface = new BoardInterface();
    std::array<Piece*, 64> chessBoard = {{
        b  , b  , b  , b  , b  , b  , b  , bkg, 
        b  , b  , bp , b  , b  , b  , b  , b  ,
        b  , b  , b  , b  , b  , b  , b  , bp ,
        wkg, wp , b  , b  , b  , b  , b  , br ,
        b  , b  , b  , b  , b  , b  , b  , bp ,
        b  , b  , b  , b  , b  , b  , b  , wp ,
        b  , b  , b  , b  , b  , b  , b  , b  ,
        b  , b  , b  , b  , b  , b  , b  , b  
    }};
    Board* b = new Board(chessBoard);
    interface->setBoard(b);
    int actualSize = getMovesAtDepth(interface, turn, n, 0);
    std::cout << "Testing: correct number of moves at depth " << n  << " returned " << actualSize << " moves." << std::endl;
    assert (actualSize == size);
}

void correct_number_of_starting_moves_at_depth_n_test_all_fixed_pos_3(int n, int size, bool turn){
    std::cout << "Testing: correct number of moves at depth " << n  << " return " << size << " moves." << std::endl;
    BoardInterface* interface = new BoardInterface();
    std::array<Piece*, 64> chessBoard = {{
        b  , b  , b  , b  , b  , b  , b  , bkg, 
        b  , b  , bp , b  , b  , b  , b  , b  ,
        wkg, b  , b  , b  , b  , b  , b  , bp ,
        b  , wp , b  , b  , b  , b  , b  , br ,
        b  , b  , b  , b  , b  , b  , b  , bp ,
        b  , b  , b  , b  , b  , b  , b  , wp ,
        b  , b  , b  , b  , b  , b  , b  , b  ,
        b  , b  , b  , b  , b  , b  , b  , b  
    }};
    Board* b = new Board(chessBoard);
    interface->setBoard(b);
    int actualSize = getMovesAtDepth(interface, turn, n, 0);
    std::cout << "Testing: correct number of moves at depth " << n  << " returned " << actualSize << " moves." << std::endl;
    assert (actualSize == size);
}

void correct_number_of_starting_moves_at_depth_n_test_all_fixed_pos_4(int n, int size, bool turn){
    std::cout << "Testing: correct number of moves at depth " << n  << " return " << size << " moves." << std::endl;
    BoardInterface* interface = new BoardInterface();
    std::array<Piece*, 64> chessBoard = {{
        b  , b  , b  , b  , b  , b  , b  , b  , 
        b  , b  , b  , b  , b  , bp , bkg, b  ,
        b  , b  , b  , b  , b  , wp , b  , b  ,
        b  , b  , b  , b  , b  , b  , b  , b  ,
        b  , b  , b  , b  , b  , b  , b  , b  ,
        bp , b  , bp , b  , b  , b  , b  , b  ,
        wp , b  , wp , bp , b  , b  , b  , b  ,
        wkg, b  , b  , wp , b  , b  , b  , b  
    }};
    Board* b = new Board(chessBoard);
    interface->setBoard(b);
    int actualSize = getMovesAtDepth(interface, turn, n, 0);
    std::cout << "Testing: correct number of moves at depth " << n  << " returned " << actualSize << " moves." << std::endl;
    assert (actualSize == size);
}

void correct_number_of_starting_moves_at_depth_n_test_all_fixed_pos_5(int n, int size, bool turn){
    std::cout << "Testing: correct number of moves at depth " << n  << " return " << size << " moves." << std::endl;
    BoardInterface* interface = new BoardInterface();
    std::array<Piece*, 64> chessBoard = {{
        bkg, b  , b  , bp , b  , b  , b  , b  , 
        bp , b  , bp , wp , b  , b  , b  , b  ,
        wp , b  , wp , b  , b  , b  , b  , b  ,
        b  , b  , b  , b  , b  , b  , b  , b  ,
        b  , b  , b  , bp , b  , b  , b  , b  ,
        bp , b  , bp , wp , b  , bp , b  , b  ,
        wp , b  , wp , b  , b  , wp , bp , b  ,
        wr , b  , b  , b  , wkg, b  , wp , b  
    }};
    Board* b = new Board(chessBoard);
    interface->setBoard(b);
    int actualSize = getMovesAtDepth(interface, turn, n, 0);
    std::cout << "Testing: correct number of moves at depth " << n  << " returned " << actualSize << " moves." << std::endl;
    assert (actualSize == size);
}

void correct_number_of_starting_moves_at_depth_n_test_all_fixed_pos_6(int n, int size, bool turn){
    std::cout << "Testing: correct number of moves at depth " << n  << " return " << size << " moves." << std::endl;
    BoardInterface* interface = new BoardInterface();
    std::array<Piece*, 64> chessBoard = {{
        b  , b  , b  , b  , b  , bp , b  , bkg, 
        b  , bp , bp , b  , b  , wp , b  , bp ,
        b  , b  , b  , b  , b  , b  , b  , wp ,
        wp , b  , b  , b  , b  , b  , b  , b  ,
        b  , b  , b ,  b  , b  , b  , b  , b  ,
        b  , b  , b  , b  , b  , b  , b  , bp ,
        b  , b  , b  , b  , b  , bp , b  , wp ,
        b  , b  , b  , b  , b  , wp , b  , wkg,
    }};
    Board* b = new Board(chessBoard);
    interface->setBoard(b);
    int actualSize = getMovesAtDepth(interface, turn, n, 0);
    std::cout << "Testing: correct number of moves at depth " << n  << " returned " << actualSize << " moves." << std::endl;
    assert (actualSize == size);
}

int main(){
    // en_passant_works_as_intended("white en passant", 3);
    // promotion_works_as_intended("white promotion", 12);
    // pawn_moves_white_works_as_intended("white pawn", 12);
    // pawn_moves_black_works_as_intended("black pawn", 11);
    // knight_moves_white_works_as_intended("white knight", 5);
    // knight_moves_black_works_as_intended("black knight", 5);
    // bishop_moves_white_works_as_intended("white bishop", 7);
    // bishop_moves_black_works_as_intended("black bishop", 5);
    // rook_moves_white_works_as_intended("white rook", 35);
    // rook_moves_black_works_as_intended("black rook", 35);
    // queen_moves_white_works_as_intended("white queen", 18);
    // queen_moves_black_works_as_intended("black queen", 18);
    // king_moves_white_works_as_intended("white king", 12);
    // king_moves_black_works_as_intended("black king", 12);
    // castle_white_not_valid_test1("white king castling", 12);
    // castle_black_not_valid_test1("black king castling", 12);
    // king_in_checkmate_no_moves("black king checkmated", 0);
    // king_in_check_moves_correctly("black king in check", 3);
    // king_in_check_moves_correctly2("white king in check", 2);
    // king_in_pin_moves_correctly("black king in pin", 27);
    // correct_number_of_starting_moves_at_depth_n_test(1, 20);
    // correct_number_of_starting_moves_at_depth_n_test(2, 400);
    // correct_number_of_starting_moves_at_depth_n_test(3, 5362);
    // correct_number_of_starting_moves_at_depth_n_test(4, 71852);
    // correct_number_of_starting_moves_at_depth_n_test(6, 9132484);
    // correct_number_of_starting_moves_at_depth_n_test_all(1, 20);
    // correct_number_of_starting_moves_at_depth_n_test_all(2, 400);
    // correct_number_of_starting_moves_at_depth_n_test_all(3, 8902);
    // correct_number_of_starting_moves_at_depth_n_test_all(4, 197281);
    // correct_number_of_starting_moves_at_depth_n_test_all(5, 4865609);
    // correct_number_of_starting_moves_at_depth_n_test_all(6, 119060324);
    // correct_number_of_starting_moves_at_depth_n_test_all_fixed_pos_1(1, 44, true);
    // correct_number_of_starting_moves_at_depth_n_test_all_fixed_pos_1(2, 1486, true);
    // correct_number_of_starting_moves_at_depth_n_test_all_fixed_pos_1(3, 62379, true);
    // correct_number_of_starting_moves_at_depth_n_test_all_fixed_pos_1(4, 2103487, true);
    correct_number_of_starting_moves_at_depth_n_test_all_fixed_pos_1(5, 89941194, true);
    // correct_number_of_starting_moves_at_depth_n_test_all_fixed_pos_2(1, 11, false);
    // correct_number_of_starting_moves_at_depth_n_test_all_fixed_pos_2(2, 35, false);
    // correct_number_of_starting_moves_at_depth_n_test_all_fixed_pos_3(1, 11, false);
    // correct_number_of_starting_moves_at_depth_n_test_all_fixed_pos_3(2, 46, false);
    // correct_number_of_starting_moves_at_depth_n_test_all_fixed_pos_4(1, 2, true);
    // correct_number_of_starting_moves_at_depth_n_test_all_fixed_pos_4(2, 7, true);
    // correct_number_of_starting_moves_at_depth_n_test_all_fixed_pos_4(3, 7, true);
    // correct_number_of_starting_moves_at_depth_n_test_all_fixed_pos_5(1, 5, true);
    // correct_number_of_starting_moves_at_depth_n_test_all_fixed_pos_5(2, 4, true);
    // correct_number_of_starting_moves_at_depth_n_test_all_fixed_pos_5(3, 16, true);
    // correct_number_of_starting_moves_at_depth_n_test_all_fixed_pos_5(4, 22, true);
    // correct_number_of_starting_moves_at_depth_n_test_all_fixed_pos_5(5, 101, true);
    // correct_number_of_starting_moves_at_depth_n_test_all_fixed_pos_6(3, 20, false);
    return 0;
}