// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <iostream>

#include "src/game.h"
#include "src/visualizer.h"
#include "src/ai.h"
#include "src/game_board.h"

int main(int argc, char* argv[]) {
    (void) argv; (void) argc;

    // get state from the user (who should go first);
    int status = -1;
    std::cout << "Who should go first? 1 for Player 1..." << std::endl;
    std::cin >> status;

    // TODO: here we need ask user what type of AI he wants
    PlayerAI* player = new PlayerAI();
    // RandomAI* ai = new RandomAI();
    MinimaxAI* ai = new MinimaxAI();

    GameBoard* gb = new GameBoard();
    Visualizer* vis = new CLI_Visualizer();

    // game should take ai as init
    // as well as status who has to go first
    Game* game = new Game(ai, player, gb, vis, status);

    int game_result = game->play();

    std::cout << game_result << std::endl;
}
