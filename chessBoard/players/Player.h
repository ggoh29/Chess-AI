#ifndef PLAYER_H
#define PLAYER_H
#include "../board/BoardInterface.h"

class Player{
  bool colour;
  public:
    Player(){};
    bool getColour(){return colour;};
    virtual int move(BoardInterface* interface, std::vector<int>* validMoves) = 0;
    virtual void winner(bool winner) = 0;
};

#endif