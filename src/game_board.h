// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

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

    ErrorCode valid_move(int i, int j);

    bool is_filled();

    int check_win();

    short to_bin(int state);

};

#endif //TEMPLATE_GAME_BOARD_H
