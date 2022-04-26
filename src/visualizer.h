// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#ifndef TEMPLATE_VISUALIZER_H
#define TEMPLATE_VISUALIZER_H

#include "game_board.h"

#include <iostream>

class Visualizer {
public:
    virtual void visualize(GameBoard& board) = 0;
};

class CLI_Visualizer : public Visualizer {
    void visualize(GameBoard& board) override;
};

#endif //TEMPLATE_VISUALIZER_H
