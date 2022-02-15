//
// Created by home on 15.02.2022.
//

#ifndef TEMPLATE_GAME_H
#define TEMPLATE_GAME_H

#include "status.h"
#include "game_board.h"
#include "ai.h"
#include "visualizer.h"

class Game {
public:

    Game(AI* ai, AI* player, GameBoard* board, Visualizer* vis, int state);

    int play(void);

    int get_state(void);

    ErrorCode set_state(int state);

private:
    GameBoard* board;
    AI* player{nullptr};
    AI* ai{nullptr};
    Visualizer* vis;
    int state;
};

#endif //TEMPLATE_GAME_H
