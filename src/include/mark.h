//
// Created by Dmitry Morozov on 17.12.2021.
//

#ifndef MARKS_MARK_H
#define MARKS_MARK_H

#include <iostream>
#include <vector>


enum class MarkType {
    None,
    HomeWork,
    Lesson,
    Test,
    Exam,
    Final
};

enum class MarkValue {
    None,
    VeryBad,
    Bad,
    Normal,
    VeryGood,
    Excellent
};



class Mark {
public:
    Mark (const std::string &subject, const MarkValue& value, ) : subject (subject), value (value),
                                                                             weight (weight) {}

    std::string subject;
    MarkValue value;
    MarkType type;
    int weight;
    int cost = 0;
};

#endif //MARKS_MARK_H
