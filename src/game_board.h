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
    std::vector<std::vector<int>> board;

    GameBoard() = default;

    ErrorCode fil_cell(size_t i, size_t j, int state);

    ErrorCode valid_move(size_t i, size_t j);

    int check_win();

};

#endif //TEMPLATE_GAME_BOARD_H
