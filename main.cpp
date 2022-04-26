// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <iostream>

#include "src/game.h"
#include "src/visualizer.h"
#include "src/ai.h"
#include "src/game_board.h"

#include <map>


/* BUGS:
 * - check win seems not work when table is full
 * - minimax could not go first, it makes stupid decisions as well
 * - add some delays I assume to (2, 3), (3, 2)
 * - add who wins
 * - add printing not only for one player
 * - minimax could not go first under any circumstances
 * - we need some game manager class I assume (to collect all the info ? )
 */

int main(int argc, char* argv[]) {
    (void) argv; (void) argc;

    std::map<size_t, AI*> m;
    m[0] =  new PlayerAI{};
    m[1] =  new RandomAI{};
    m[2] =  new MinimaxAI{};

    // get state from the user (who should go first);
    int status = -1;
    std::cout << "real: 1, random: 2, minimax: 3" << std::endl;

    // get first player
    std::cout << "Who should go first?" << std::endl;
    std::cin >> status;
    if (!(status > 0 && status < 4)) {
        std::cerr << "Bad choice..." << std::endl;
        exit(1);
    }
    AI* first_player = m[status - 1];

    std::cout << "Who should go second?" << std::endl;
    std::cin >> status;
    if (!(status > 0 && status < 4)) {
        std::cerr << "Bad choice..." << std::endl;
        exit(1);
    }
    AI* second_player = m[status - 1];

    GameBoard* gb = new GameBoard();
    Visualizer* vis = new CLI_Visualizer();

    // game should take ai as init
    // as well as status who has to go first
    Game* game = new Game(first_player, second_player, gb, vis);
    int game_result = game->play();

    std::cout << game_result << std::endl;
}
