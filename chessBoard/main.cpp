#include "./board/BoardInterface.h"
#include "./players/Player.h"
#include "./players/HumanPlayer.h"
#include <vector>

bool checkIfOver(BoardInterface* interface, std::vector<int>* validMoves){
    return validMoves->empty();
}

int finalScore(BoardInterface* interface, bool colour){
    return interface->getWinner(colour);
}

int getPlayerMove(BoardInterface* interface, Player* player, bool turn){
    std::vector<int>* validMoves = interface -> getValidMoves(turn);
    bool gameOver = checkIfOver(interface, validMoves);
    if(gameOver){
        delete validMoves;
        return -1;
    }
    int move = player->move(interface, validMoves);
    delete validMoves;
    return move;
}

int main(){
    BoardInterface* interface = new BoardInterface();
    Player* playerWhite = new HumanPlayer(1);
    Player* playerBlack = new HumanPlayer(0);
    bool turn = true;
    int playerMove = 0;
    while (playerMove != -1){   
        std::cout << turn << std::endl;
        int playerMove = getPlayerMove(interface, (turn ? playerWhite : playerBlack), turn);
        if (playerMove == -1){
            break;
        }
        interface -> makeMove(playerMove);
        turn =  1 - turn;
    }
    interface -> printBoard();
    std::cout << (turn ? "Black" : "White") << " Won, score " << finalScore(interface, turn)  << std::endl;
};  