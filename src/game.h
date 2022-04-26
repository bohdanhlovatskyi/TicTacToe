// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#ifndef TEMPLATE_GAME_H
#define TEMPLATE_GAME_H

#include "status.h"
#include "game_board.h"
#include "ai.h"
#include "visualizer.h"

class Game {
public:
    // first player goes by default, thus state{1}
    Game(): first_player{nullptr}, second_player{nullptr},
            board{nullptr}, visualizer{nullptr}, pl_move{1} {};

    // priority inversion constructor, can be constructed for
    // instance from values stored in file to make different experiments
    Game(AI* fp, AI* sp, GameBoard* brd, Visualizer* vis): \
                    first_player{fp}, second_player{sp},
                    board{brd}, visualizer{vis}, pl_move{1} {};

    int play(void);
    int get_state(void);
    ErrorCode set_state(int state);

private:
    GameBoard* board;
    AI* first_player;
    AI* second_player;
    Visualizer* visualizer;
    int pl_move;
};

#endif //TEMPLATE_GAME_H
