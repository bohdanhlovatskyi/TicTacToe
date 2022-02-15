//
// Created by home on 15.02.2022.
//

#ifndef TEMPLATE_GAME_BOARD_H
#define TEMPLATE_GAME_BOARD_H

#include "status.h"

#include <vector>

constexpr int BOARD_SIZE = 3;

class GameBoard {
public:
    GameBoard() = default;

    ErrorCode fil_cell(size_t i, size_t j);

    ErrorCode valid_move(size_t i, size_t j);

private:
    std::vector<std::vector<int>> board;
};

#endif //TEMPLATE_GAME_BOARD_H
