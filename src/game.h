//
// Created by home on 15.02.2022.
//

#ifndef TEMPLATE_GAME_H
#define TEMPLATE_GAME_H

#include "status.h"
#include "game_board.h"

class Game {
public:

    Game(AI ai, AI player, Config config) {
        this->ai = ai;
        this->player = player;
        this->config = config;
    }

    int play(void);

private:
    GameBoard board;
    AI player, ai;
};

#endif //TEMPLATE_GAME_H
