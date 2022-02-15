//
// Created by home on 15.02.2022.
//

#include "game_board.h"

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

int GameBoard::check_win() {
    return -1;
}