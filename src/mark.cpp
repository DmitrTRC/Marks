//
// Created by Dmitry Morozov on 17.12.2021.
//

#include "mark.h"
#include <algorithm>
#include <utility>



Mark::Mark (std::string subject_, const MarkValue &value_, const MarkType &type_) : subject (std::move(subject_)),
                                                                                           value (value_),
                                                                                           type (type_) {}

//Returns enumerated list of Subject values
std::map<int, std::string> Mark::getSubjects () {
    std::map<int, std::string> subjects;
    for (const auto &[key, value]: subjectMap) {

        //Converts for Emum class to int and add to map
        subjects.insert ({static_cast<int>( value), key});
    }
    return subjects;
}