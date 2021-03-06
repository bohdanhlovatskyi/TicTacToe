// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "game.h"

int Game::play() {

    for (;;) {
        auto state = get_state();

        std::pair<int, int> next_move;
        switch (state) {
            case 1:
                next_move = first_player->next_move(*board, state);
                break;
            case 2:
                next_move = second_player->next_move(*board, state);
                break;
        }

        board->fil_cell(next_move.first, next_move.second, state); // -V106

        // board should take visualizer class then
        visualizer->visualize(*board);

        if (board->check_win() != -1) {
            return board->check_win();
        }

        set_state(get_state() == 1 ? 2 : 1);
    }

}

int Game::get_state() {
    return pl_move;
}

ErrorCode Game::set_state(int state) {
    if (state == 1 || state == 2) {
        pl_move = state;
        return ErrorCode::OK;
    }

    return ErrorCode::STATE_OUT_OF_RANGE;
}