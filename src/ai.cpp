//
// Created by home on 15.02.2022.
//

#include "ai.h"
#include "game_board.h"
#include "status.h"

pair<int, int> PlayerAI::next_move(const GameBoard &board) {
    int i = -1, j = -1;

    while (board.valid_move(i, j) != ErrorCode::OK) {
        std::cout << "Enter the valid free cell" << std::endl;
        cin >> i >> j;
    }

    return std::make_pair(i, j);
}

pair<int, int> RandomAI::next_move(const GameBoard &board) {
    int i = rand() % 4, j = rand() % 4;

    while (board.valid_move(i, j) != ErrorCode::OK) {
        i = rand() % 4;
        j = rand() % 4;
    }

    return std::make_pair(i, j);
}