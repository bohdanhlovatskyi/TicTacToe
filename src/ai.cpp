//
// Created by home on 15.02.2022.
//

#include "ai.h"
#include "game_board.h"
#include "status.h"

std::pair<int, int> PlayerAI::next_move(GameBoard &board, int status) {
    (void) status;

    int i = -1, j = -1;

    while (board.valid_move(i, j) != ErrorCode::OK) {
        std::cout << "Enter the valid free cell" << std::endl;
        std::cin >> i >> j;
    }

    return std::make_pair(i, j);
}

std::pair<int, int> RandomAI::next_move(GameBoard &board, int status) {
    (void) status;

    int i = rand() % 4, j = rand() % 4;

    while (board.valid_move(i, j) != ErrorCode::OK) {
        i = rand() % 4;
        j = rand() % 4;
    }

    std::cout << "RandomAI has made his move: (" << i << ", " << j << ")" << std::endl;

    return std::make_pair(i, j);
}

std::pair<int, int> MinimaxAI::next_move(GameBoard &board, int status) {

    auto best_res = -1000;
    int bi = -1, bj = -1;

    for (size_t i = 0; i < BOARD_SIZE; ++i) {
        for (size_t j = 0; j < BOARD_SIZE; ++j) {
            if (board.board[i][j] != 0) continue;

            board.board[i][j] = status;
            auto mm = minimax(board, 0, status == 1 ? 2 : 1);
            board.board[i][j] = 0;

            if (mm > best_res) {
                best_res = mm;
                bi = i;
                bj = j;
            }

        }
    }

    return std::make_pair(bi, bj);
}

int MinimaxAI::evaluate(GameBoard &board) {
    auto res = board.check_win();

    int ret{};
    if (res == 2) {
        ret = -10;
    } else if (res == 1) {
        ret = 10;
    } else {
        ret = 0;
    }

    return ret;
}

int MinimaxAI::minimax(GameBoard &board, int depth, int status) {
    auto score = this->evaluate(board);

    // one of the players win
    if (score != 0) return score;

    // draw case
    if (board.is_filled()) return 0;

    auto best = status == 2 ? -1000 : 1000;

    for (size_t i = 0 ; i < BOARD_SIZE; ++i) {
        for (size_t j = 0; j < BOARD_SIZE; ++j) {
            if (board.board[i][j] != 0) continue;

            board.board[i][j] = status;
            if (status == 1) {
                best = std::max(best, minimax(board,depth + 1,2));
            } else if (status == 2) {
                best = std::min(best, minimax(board,depth + 1,1));
            }
            board.board[i][j] = 0;
        }
    }

    return best;
}