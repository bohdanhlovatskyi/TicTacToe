//
// Created by home on 15.02.2022.
//

#include "visualizer.h"

int CLI_Visualizer::visualize(GameBoard &board) {
    for (size_t i = 0; i < BOARD_SIZE; i++) {
        for (size_t j = 0; j < BOARD_SIZE; j++) {
            std::cout << board.board[i][j] << "| ";
        }
        std::cout << std::endl;
    }

    return 0;
}