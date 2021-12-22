//
// Created by Dmitry Morozov on 17.12.2021.
//

#ifndef MARKS_MARK_H
#define MARKS_MARK_H

#include <iostream>
#include <vector>
#include <map>


enum class MarkType {
    None,
    HomeWork,
    Lesson,
    Test,
    Exam,
    Final
};

std::map<std::string, MarkType> markTypeMap = {
        {"None",     MarkType::None},
        {"HomeWork", MarkType::HomeWork},
        {"Lesson",   MarkType::Lesson},
        {"Test",     MarkType::Test},
        {"Exam",     MarkType::Exam},
        {"Final",    MarkType::Final}
};

enum class MarkValue {
    None,
    VeryBad,
    Bad,
    Normal,
    VeryGood,
    Excellent
};

std::map<std::string, MarkValue> markValueMap = {
        {"None",      MarkValue::None},
        {"VeryBad",   MarkValue::VeryBad},
        {"Bad",       MarkValue::Bad},
        {"Normal",    MarkValue::Normal},
        {"VeryGood",  MarkValue::VeryGood},
        {"Excellent", MarkValue::Excellent},
        {"0",         MarkValue::None},
        {"1",         MarkValue::VeryBad},
        {"2",         MarkValue::Bad},
        {"3",         MarkValue::Normal},
        {"4",         MarkValue::VeryGood},
        {"5",         MarkValue::Excellent}
};


class Mark {
public:
    Mark (const std::string &subject, const MarkValue &value,) : subject (subject), value (value),
                                                                 weight (weight) {}

    std::string subject;
    MarkValue value;
    MarkType type;
    int weight;
    int cost = 0;
};

#endif //MARKS_MARK_H
