//
// Created by Dmitry Morozov on 23.12.2021.
//

#include "screen_util.h"


void clearScreen (const int rows ) {
    std::cout << std::string (rows, '\n');
}