#include "BoardInterface.h"

BoardInterface::BoardInterface() : 
board(new Board()),
moveslist(new std::vector<int>()), 
undoMoveslist(new std::vector<int>()),
turn(true){}

void BoardInterface::setBoard(Board* b){
    delete this->board;
    this->board = b;
}

unsigned long BoardInterface::getHash(){
    return board->getHash();
}

void BoardInterface::makeMove(int move){
    this->makeMove(this->turn, move);
};

void BoardInterface::makeMove(bool turn, int move){
    Move moveDocoder = Move();
    std::array<int, 4> mv = moveDocoder.decodeMove(move);
    int capturedPiece = board->pieceEnumAtLocation(mv[2], mv[3]);
    int castlingState = board->getCastlingState();
    int undoMove = moveDocoder.encodeUndoMove(move, capturedPiece);
    int undoMoveWCastlingState = moveDocoder.encodeCastlingState(undoMove, castlingState);
    board->makeMove(turn, move);
    moveslist->push_back(move);
    undoMoveslist->push_back(undoMoveWCastlingState);
};

void BoardInterface::undoMove(){
    this->undoMove(this->turn);
};

void BoardInterface::undoMove(bool turn){
    if (!this->undoMoveslist->empty()){
        Move moveDocoder = Move();
        int undoMove = undoMoveslist->back();
        int castlingState = moveDocoder.decodeCastlingState(undoMove);
        this->board->undoMove(turn, undoMove, castlingState);
        undoMoveslist->pop_back();
        moveslist->pop_back();
    }
};

void BoardInterface::printMove(int move){
    board->printMove(move);
    std::cout << std::endl;
}

std::vector<int>* BoardInterface::getMoves(){
    return this->getMoves(this->turn);
}

std::vector<int>* BoardInterface::getMoves(bool turn){
    int lastMove = 0;
    if (!moveslist->empty()){
        lastMove = moveslist->back();
    }
    return board->getMoves(turn, lastMove);
}

std::vector<int>* BoardInterface::getValidMoves(){
    return this->getValidMoves(this->turn);
}

std::vector<int>* BoardInterface::getValidMoves(bool turn){
    std::vector<int>*  moves = this->getMoves(turn);
    int i_king, j_king;
    bool b = false;
    for (i_king = 0 ; i_king < 8; i_king++) {
        for (j_king = 0; j_king < 8; j_king++) {
            if (board->pieceEnumAtLocation(i_king, j_king) == (turn ?  6 : 14)){
                b = true;
                break;
            };
        }
        if (b){
            break;
        }
    }
    if (!b){
        delete moves;
        return new std::vector<int>();
    }
    Move* moveDocoder = new Move();
    moves->erase(std::remove_if(moves->begin(), moves->end(), [this, turn, moveDocoder, i_king, j_king](int mv) {
        std::array<int, 4> move = moveDocoder->decodeMove(mv);
        int capturedPiece = board->pieceEnumAtLocation(move[2], move[3]);
        int undoMove = moveDocoder->encodeUndoMove(mv, capturedPiece);
        int castlingState = board->getCastlingState();
        board->makeMove(turn, mv);
        bool del = false;
        if ((1 << 28) & mv){
            for (int col : {2, 3, 4}){
                del |= !board->isValidPosforKing(turn ? 7 : 0, col, turn);
            }
            del |= (castlingState & (turn ? 4 : 32)) || (castlingState & (turn ? 2 : 16));
        } else if ((1 << 29) & mv){
            for (int col : {4, 5, 6}){
                del |= !board->isValidPosforKing(turn ? 7 : 0, col, turn);
            }
            del |= (castlingState & (turn ? 4 : 32)) || (castlingState & (turn ? 1 : 8));
        } else {
            if (move[0] == i_king && move[1] == j_king){
                del |= !board->isValidPosforKing(move[2], move[3], turn);
            } else {
                del |= !board->isValidPosforKing(i_king, j_king, turn);
            }
        }
        board->undoMove(turn, undoMove, castlingState);
        return del;
    }), moves->end());
    delete moveDocoder;
    return moves;
};