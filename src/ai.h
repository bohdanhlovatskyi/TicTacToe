//
// Created by home on 15.02.2022.
//

#ifndef TEMPLATE_AI_H
#define TEMPLATE_AI_H

#include "status.h"
#include "game_board.h"

#include <random>
#include <iostream>

#include <torch/script.h>

class AI {
public:
    virtual std::pair<int, int> next_move(GameBoard& board) = 0;
};

class RandomAI : public AI {
public:
    std::pair<int, int> next_move(GameBoard& board) override;
};

class PlayerAI : public AI {
public:
    std::pair<int, int> next_move(GameBoard& board) override;
};

class NN_AI : public AI {
public:
    std::pair<int, int> next_move(GameBoard& board) override;

    void load_model(std::string path);

private:
    torch::jit::script::Module module;
};

#endif //TEMPLATE_AI_H
