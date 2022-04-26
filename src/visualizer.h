//
// Created by home on 15.02.2022.
//

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
