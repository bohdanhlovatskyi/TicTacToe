//
// Created by home on 15.02.2022.
//

#include "game_board.h"

const std::vector<short> wc = {
        // each row
        0b000000111,
        0b000111000,
        0b111000000,
        // each column
        0b100100100,
        0b010010010,
        0b001001001,
        // each diagonal
        0b100010001,
        0b001010100
};

ErrorCode GameBoard::valid_move(size_t i, size_t j) {
    if ((i < 0 || i >= BOARD_SIZE) ||
        (j < 0 || j >= BOARD_SIZE)) {
        return ErrorCode::INDEX_OUT_OF_BOUNDS;
    }

    if (this->board[i][j] != 0) {
        return ErrorCode::CELL_IS_TAKEN;
    }

    return ErrorCode::OK;
}

ErrorCode GameBoard::fil_cell(size_t i, size_t j, int player) {
    ErrorCode valid = valid_move(i, j);
    if (valid != ErrorCode::OK) {
        return valid;
    }

    this->board[i][j] = player;

    return ErrorCode::OK;
}

short GameBoard::to_bin(int state) {
    // TODO: 3 is lame
    short x = 0;
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; j++) {
            // TODO: as well as 1 here is lame
            if (this->board[i][j] == state) {
                x = ((1 << (3 * i + j)) | x);
            }
        }
    }


    return x;
}

// TODO: add return codes
int GameBoard::check_win() {

    auto x = this->to_bin(1);

    for (int i = 0; i < 8; i++)
        if ((x & wc[i]) == wc[i])
            return 1;

    auto o = this->to_bin(2);
    for (int i = 0; i < 8; i++)
        if ((o & wc[i]) == wc[i])
            return 2;

    return -1;
}