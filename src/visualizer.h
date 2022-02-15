//
// Created by home on 15.02.2022.
//

#ifndef TEMPLATE_VISUALIZER_H
#define TEMPLATE_VISUALIZER_H

#include "game_board.h"

#include <iostream>

class Visualizer {
public:

    Visualizer(GameBoard& board);

    Visualizer();

    virtual int visualize(void) = 0;

    GameBoard board;
};


class CLI_Visualizer : public Visualizer {

    using Visualizer::Visualizer;

    int visualize(void) override;
};

#endif //TEMPLATE_VISUALIZER_H
