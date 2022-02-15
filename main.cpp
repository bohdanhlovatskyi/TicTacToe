// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <iostream>
#include <torch/torch.h>

#include "game.h"

int main(int argc, char* argv[]) {
    torch::Tensor tensor = torch::rand({2, 3});
    std::cout << tensor << std::endl;


    // game should take ai as init
    // as well as status who has to go first
    Game game = new Game();

    int game_result = game.play();

    std::cout << game_result << std::endl;
}
