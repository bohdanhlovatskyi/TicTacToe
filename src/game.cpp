//
// Created by home on 15.02.2022.
//

#include "game.h"

int Game::play(bool visualize) {

    for (;;) {
        auto state = this.get_state();

        std::pair<int, int> next_move;

        // note that here we determine validity of next_move
        // in the corresponding method
        switch (state) {
            case 1:
                next_move = this->player.next_move();
                break;
            case 2:
                next_move = this->ai.next_move();
                break;
        }

        this->board.fil_cell(next_move.first, next_move.second, state);

        // board should take visualizer class then
        this->board.visualize();

        auto result = this->board.check_win();
        if (result != -1) {
            return result;
        }
    }

}