// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "ai.h"
#include "game_board.h"
#include "status.h"

std::pair<int, int> PlayerAI::next_move(GameBoard &board, int pl_move) {
    (void) pl_move;

    int i = -1, j = -1;

    // this one smalls here... should be put out of the func in order
    // to make the visualizer be able to reach the message
    while (board.valid_move(i, j) != ErrorCode::OK) {
        std::cout << "Enter the valid free cell" << std::endl;
        std::cin >> i >> j;
    }

    return std::make_pair(i, j);
}

std::pair<int, int> RandomAI::next_move(GameBoard &board, int status) {
    (void) status;

    int i = rand() % BOARD_SIZE, j = rand() % BOARD_SIZE;

    while (board.valid_move(i, j) != ErrorCode::OK) {
        i = rand() % BOARD_SIZE;
        j = rand() % BOARD_SIZE;
    }

    std::cout << "RandomAI has made his move: (" << i << ", " << j << ")" << std::endl;

    return std::make_pair(i, j);
}

std::pair<int, int> MinimaxAI::next_move(GameBoard &board, int status) {
    auto best_res = -1000;
    int bi = -1, bj = -1;

    initial_player = status;

    for (size_t i = 0; i < BOARD_SIZE; ++i) {
        for (size_t j = 0; j < BOARD_SIZE; ++j) {
            if (board.board[i][j] != 0) continue;

            board.board[i][j] = status;

            // this smells...
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

int MinimaxAI::evaluate(GameBoard &board) const {
    auto res = board.check_win();

    int ret{};

    if (res == -1) {
        ret = 0;
    } else if (res == initial_player) {
        ret = 10;
    } else if (res != initial_player) {
        ret = -10;
    }

    return ret;
}

int MinimaxAI::minimax(GameBoard &board, int depth, int status) {
    auto score = evaluate(board);

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