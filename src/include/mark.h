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


enum class MarkValue {
    None,
    VeryBad,
    Bad,
    Normal,
    VeryGood,
    Excellent
};

enum class Subjects {
    None,
    Algorithms,
    Cpp,
    Python,
    Java,
    C,
    CSharp,
    HTML,
    CSS,
    JS,
    PHP,
    SQL,
    JavaScript,
    Pascal,
    Basic,
    Assembly,
    Math,
    Physics,
    ComputerScience
};

const std::map<std::string, MarkType> markTypeMap = {
        {"None",     MarkType::None},
        {"HomeWork", MarkType::HomeWork},
        {"Lesson",   MarkType::Lesson},
        {"Test",     MarkType::Test},
        {"Exam",     MarkType::Exam},
        {"Final",    MarkType::Final}
};

const std::map<std::string, Subjects> subjectMap = {
        {"None",            Subjects::None},
        {"Algorithms",      Subjects::Algorithms},
        {"C++",             Subjects::Cpp},
        {"Python",          Subjects::Python},
        {"Java",            Subjects::Java},
        {"C",               Subjects::C},
        {"C#",              Subjects::CSharp},
        {"HTML",            Subjects::HTML},
        {"CSS",             Subjects::CSS},
        {"JS",              Subjects::JS},
        {"PHP",             Subjects::PHP},
        {"SQL",             Subjects::SQL},
        {"JavaScript",      Subjects::JavaScript},
        {"Pascal",          Subjects::Pascal},
        {"Basic",           Subjects::Basic},
        {"Assembly",        Subjects::Assembly},
        {"Math",            Subjects::Math},
        {"Physics",         Subjects::Physics},
        {"ComputerScience", Subjects::ComputerScience}
};

const std::map<std::string, MarkValue> markValueMap = {
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
    Mark (const std::string &, const MarkValue &, const MarkType &);


    void getMarksValues ();

    void getMarksTypes ();

    static std::map<int, std::string> getSubjects () ;

private:
    std::string subject;
    MarkValue value;
    MarkType type;
    int weight;
    int cost = 0;
};

#endif //MARKS_MARK_H