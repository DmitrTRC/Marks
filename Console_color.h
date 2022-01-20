//
// Created by Dmitry Morozov on 20.01.2022.
//

#ifndef MARKS_CONSOLE_COLOR_H
#define MARKS_CONSOLE_COLOR_H

#include <iostream>


namespace Color {
    enum Code {
        FG_RED = 31,
        FG_GREEN = 32,
        FG_BLUE = 34,
        FG_DEFAULT = 39,
        BG_RED = 41,
        BG_GREEN = 42,
        BG_BLUE = 44,
        BG_DEFAULT = 49
    };

    class Modifier {
        Code code;
    public:
        explicit Modifier (Code pCode) : code (pCode) {}

        friend std::ostream &operator<< (std::ostream &os, const Modifier &mod) {
            return os << "\033[" << mod.code << "m";
        }
    };
}

#endif //MARKS_CONSOLE_COLOR_H
