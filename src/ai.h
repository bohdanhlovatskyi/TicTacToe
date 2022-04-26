// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#ifndef TEMPLATE_AI_H
#define TEMPLATE_AI_H

#include "status.h"
#include "game_board.h"

#include <random>
#include <iostream>

constexpr size_t AI_COUNT = 3;

// interface method
class AI {
public:
    virtual std::pair<int, int> next_move(GameBoard& board, int pl_move) = 0;
};

class RandomAI : public AI {
public:
    std::pair<int, int> next_move(GameBoard& board, int pl_move) override final;
};

class PlayerAI : public AI {
public:
    std::pair<int, int> next_move(GameBoard& board, int pl_move) override final;
};

class MinimaxAI : public AI {
public:
    std::pair<int, int> next_move(GameBoard& board, int pl_move) override final;
private:
    int initial_player;

    int evaluate(GameBoard& board) const;
    int minimax(GameBoard& board, int depth, int status);
};

#endif //TEMPLATE_AI_H
