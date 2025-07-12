#ifndef BOTPLAYER_H
#define BOTPLAYER_H
#include "./Player.h"
#include <stdio.h>
#include <vector>
#include <torch/script.h> // For TorchScript
#include <torch/torch.h>  // For general PyTorch operations

class HumanPlayer:public Player{
  bool colour;
  public:
    HumanPlayer(bool colour);
    int move(BoardInterface* interface, std::vector<int>* validMoves);
};

#endif