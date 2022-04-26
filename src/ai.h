//
// Created by home on 15.02.2022.
//

#ifndef TEMPLATE_AI_H
#define TEMPLATE_AI_H

#include "status.h"
#include "game_board.h"

#include <random>
#include <iostream>

// interface method
class AI {
public:
    virtual std::pair<int, int> next_move(GameBoard& board, int status) = 0;
};

class RandomAI : public AI {
public:
    std::pair<int, int> next_move(GameBoard& board, int status) override final;
};

class PlayerAI : public AI {
public:
    std::pair<int, int> next_move(GameBoard& board, int status) override final;
};

class MinimaxAI : public AI {
public:
    std::pair<int, int> next_move(GameBoard& board, int status) override final;

private:
    int evaluate(GameBoard& board);
    int minimax(GameBoard& board, int depth, int status);
};

#endif //TEMPLATE_AI_H
