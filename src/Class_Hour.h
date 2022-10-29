//
// Created by feld on 20-10-2022.
//

#ifndef AED_CLASS_HOUR_H
#define AED_CLASS_HOUR_H

#include <string>
#include <vector>
#include "Lecture.h"

class Class_Hour {
public:
    std::vector<Lecture> lectures;
    std::string ucName, name;
    Class_Hour(std::string name, std::string ucName);
};


#endif
