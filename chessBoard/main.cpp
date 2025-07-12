#include "./board/BoardInterface.h"
#include "./players/Player.h"
#include "./players/HumanPlayer.h"
#include <vector>
#include <torch/script.h> // For TorchScript
#include <torch/torch.h>  // For general PyTorch operations

// bool checkIfOver(BoardInterface* interface, std::vector<int>* validMoves){
//     return validMoves->empty();
// }

// int finalScore(BoardInterface* interface, bool colour){
//     return interface->getWinner(colour);
// }

// int getPlayerMove(BoardInterface* interface, Player* player, bool turn){
//     std::vector<int>* validMoves = interface -> getValidMoves(turn);
//     bool gameOver = checkIfOver(interface, validMoves);
//     if(gameOver){
//         delete validMoves;
//         return -1;
//     }
//     int move = player->move(interface, validMoves);
//     delete validMoves;
//     return move;
// }

// int main(){
//     BoardInterface* interface = new BoardInterface();
//     Player* playerWhite = new HumanPlayer(1);
//     Player* playerBlack = new HumanPlayer(0);
//     bool turn = true;
//     int playerMove = 0;
//     while (playerMove != -1){   
//         std::cout << turn << std::endl;
//         int playerMove = getPlayerMove(interface, (turn ? playerWhite : playerBlack), turn);
//         if (playerMove == -1){
//             break;
//         }
//         interface -> makeMove(playerMove);
//         turn =  1 - turn;
//     }
//     interface -> printBoard();
//     std::cout << (turn ? "Black" : "White") << " Won, score " << finalScore(interface, turn)  << std::endl;
// };  

int main() {
    // Check for CUDA availability
    if (torch::cuda::is_available()) {
        std::cout << "CUDA is available! Using GPU." << std::endl;
    } else {
        std::cout << "CUDA not available. Using CPU." << std::endl;
        return 1; // Or handle CPU fallback
    }

    // Load a TorchScript model
    torch::jit::Module model;
    try {
        model = torch::jit::load("path/to/your/model.pt");
    } catch (const c10::Error& e) {
        std::cerr << "Error loading the model: " << e.msg() << std::endl;
        return -1;
    }

    // Move the model to GPU
    model.to(torch::kCUDA);

    // Create a dummy input tensor and move it to GPU
    auto input = torch::rand({1, 3, 224, 224}).to(torch::kCUDA);

    // Perform inference
    auto output = model.forward({input}).toTensor();

    std::cout << "Output shape: " << output.sizes() << std::endl;

    return 0;
}