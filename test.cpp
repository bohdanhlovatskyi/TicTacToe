// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <iostream>
#include <torch/torch.h>

#include "src/game.h"
#include "src/visualizer.h"
#include "src/ai.h"
#include "src/game_board.h"

int main(int argc, char* argv[]) {
    (void) argv; (void) argc;

    double board[] = {1, 0, 0, 1, 0, 1, 0, 0, 0};
    auto options = torch::TensorOptions().dtype(torch::kFloat64);
    torch::Tensor tensor = torch::from_blob(board, {9}, options);
    std::cout << tensor << std::endl;

    NN_AI* ai = new NN_AI();

    std::string path = "../model.pt";
    ai->load_model(std::string{path});
}
