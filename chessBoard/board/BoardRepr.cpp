#include "BoardRepr.h"

BoardRepr::BoardRepr(std::array<int, 8> boardRepr) : boardRepr{boardRepr}
{};

int BoardRepr::getPieceEnumAt(int x, int y){
    int y_axis = this->boardRepr[x];
    return (y_axis >> (4 * y)) & 15;
}

void BoardRepr::putPieceEnum(int x, int y, int e){
    int existing = this->boardRepr[x] >> (4 * y) & 15;
    boardRepr[x] = boardRepr[x] ^ ((e ^ existing) & 15) << (4 * y);
}