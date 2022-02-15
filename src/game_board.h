//
// Created by home on 15.02.2022.
//

#ifndef TEMPLATE_GAME_BOARD_H
#define TEMPLATE_GAME_BOARD_H

#include "status.h"

#include <vector>
#include <iostream>

constexpr int BOARD_SIZE = 3;

class GameBoard {
public:
    // TODO: 3 here is lame
    std::vector<std::vector<int>> board;

    GameBoard(): board(3, std::vector<int>(3, 0)) {};

    ErrorCode fil_cell(size_t i, size_t j, int state);

    ErrorCode valid_move(size_t i, size_t j);

    int check_win();

    short to_bin(int state);

};

#endif //TEMPLATE_GAME_BOARD_H
