#include "./HumanPlayer.h"

HumanPlayer::HumanPlayer(bool colour):colour(colour){};

int HumanPlayer::move(BoardInterface* interface, std::vector<int>* validMoves){
    interface -> printBoard();
    std::cout << (colour ? "White's" : "Black's") << " turn to move" << std::endl;
    int i = 0;
    for (auto validMove : *validMoves){
        std::cout << i << " : "; 
        interface -> printMove(validMove);
        i++;
    }
    int option;
    std::cin >> option;
    option = validMoves -> at(option);
    return option;
}