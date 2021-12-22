//
// Created by Dmitry Morozov on 17.12.2021.
//

#ifndef MARKS_MARK_H
#define MARKS_MARK_H

#include <iostream>
#include <vector>


class Mark {
public:
    Mark (const std::string &subject, const int &value, const int &weight) : subject (subject), value (value),
                                                                             weight (weight) {}

    std::string subject;
    int value;
    int weight;
    std::vector<int> marks = {5, 4, 4, 3, 3};
};

#endif //MARKS_MARK_H
