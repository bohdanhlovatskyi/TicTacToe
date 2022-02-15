//
// Created by home on 15.02.2022.
//

#ifndef TEMPLATE_VISUALIZER_H
#define TEMPLATE_VISUALIZER_H

#include "game_board.h"

class Visualizer {
public:

    Visualizer(GameBoard& board);

    virtual int visualize(void);

private:
    GameBoard board;
};

class CLI_Visualizer : public Visualizer {
    int visualize(void);
};

#endif //TEMPLATE_VISUALIZER_H
