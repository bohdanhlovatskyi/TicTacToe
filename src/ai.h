//
// Created by home on 15.02.2022.
//

#ifndef TEMPLATE_AI_H
#define TEMPLATE_AI_H

#include "status.h"
#include "game_board.h"

#include <random>

class AI {
public:
    virtual std::pair<int, int> next_move(const GameBoard& board);
};

// TODO: looks lame
class RandomAI : public AI {
    std::pair<int, int> next_move(const GameBoard& board);
};

class PlayerAI : public AI {
    std::pair<int, int> next_move(const GameBoard& board);
};

#endif //TEMPLATE_AI_H
