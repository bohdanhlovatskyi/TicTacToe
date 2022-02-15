//
// Created by home on 15.02.2022.
//

#include "game.h"

Game::Game(AI* ai, AI* player, GameBoard* board, Visualizer* vis, int state) {
    this->ai = ai;
    this->player = player;
    this->board = board;
    this->vis = vis;
    this->state = state;
}

int Game::play() {

    for (;;) {
        auto state = this->get_state();

        std::pair<int, int> next_move;

        // note that here we determine validity of next_move
        // in the corresponding method
        switch (state) {
            case 1:
                next_move = this->player->next_move(*this->board);
                break;
            case 2:
                next_move = this->ai->next_move(*this->board);
                break;
        }

        this->board->fil_cell(next_move.first, next_move.second, state);

        // board should take visualizer class then
        this->vis->visualize(*this->board);

        auto result = this->board->check_win();
        if (result != -1) {
            return result;
        }

        this->set_state(this->get_state() == 1 ? 2 : 1);
    }

}

int Game::get_state() {
    return this->state;
}

ErrorCode Game::set_state(int state) {
    if (state == 1 || state == 2) {
        this->state = state;
        return ErrorCode::OK;
    }

    return ErrorCode::STATE_OUT_OF_RANGE;
}