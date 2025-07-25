#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H
#include "./Player.h"
#include <stdio.h>
#include <vector>

class HumanPlayer:public Player{
  bool colour;
  public:
    HumanPlayer(bool colour);
    int move(BoardInterface* interface, std::vector<int>* validMoves);
    void winner(bool winner) = 0;
};

#endif