//
// Created by home on 15.02.2022.
//

#include "ai.h"
#include "game_board.h"
#include "status.h"

std::pair<int, int> PlayerAI::next_move(GameBoard &board) {
    int i = -1, j = -1;

    while (board.valid_move(i, j) != ErrorCode::OK) {
        std::cout << "Enter the valid free cell" << std::endl;
        std::cin >> i >> j;
    }

    return std::make_pair(i, j);
}

std::pair<int, int> RandomAI::next_move(GameBoard &board) {
    int i = rand() % 4, j = rand() % 4;

    while (board.valid_move(i, j) != ErrorCode::OK) {
        i = rand() % 4;
        j = rand() % 4;
    }

    std::cout << "RandomAI has made his move: (" << i << ", " << j << ")" << std::endl;

    return std::make_pair(i, j);
}