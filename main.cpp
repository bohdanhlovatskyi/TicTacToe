// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <iostream>

#include "src/game.h"
#include "src/visualizer.h"
#include "src/ai.h"
#include "src/game_board.h"

#include <map>

std::map<size_t, AI*> m = {
        {0, new PlayerAI{}},
        {1, new RandomAI{}},
        {2, new MinimaxAI{}}
};

AI* get_player() {
    int status = -1;
    std::cout << "Choose player: " << std::endl;
    std::cin >> status;
    if (!(status > 0 && status < 4)) {
        std::cerr << "Bad choice..." << std::endl;
        exit(1);
    }

    return m[status - 1];
}

int main(int argc, char* argv[]) {
    (void) argv; (void) argc;

    // all of the following information could be collected by
    // GameManager class (imho it would be weird for a game to
    // collect all the info), though at the current stage
    // it would bring complexity that is not needed yet

    // get the players
    std::cout << "real: 1, random: 2, minimax: 3" << std::endl;
    AI* first_player = get_player();
    AI* second_player = get_player();

    // create default board and visualizer - again, the most
    // suitable place for their creation - game manager
    // that would contain all the user - provided settings
    GameBoard* gb = new GameBoard();
    Visualizer* vis = new CLI_Visualizer();

    Game* game = new Game(first_player, second_player, gb, vis);
    int game_result = game->play();
    std::cout << game_result << " player has won." << std::endl;

    return 0;
}
