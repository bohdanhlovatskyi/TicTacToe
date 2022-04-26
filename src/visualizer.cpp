// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

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