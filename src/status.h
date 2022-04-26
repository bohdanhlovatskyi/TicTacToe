// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#ifndef TEMPLATE_STATUS_H
#define TEMPLATE_STATUS_H

enum class ErrorCode {
    OK=0,
    INDEX_OUT_OF_BOUNDS,
    CELL_IS_TAKEN,
    STATE_OUT_OF_RANGE
};

#endif //TEMPLATE_STATUS_H
