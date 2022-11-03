#ifndef AED_CLASS_HOUR_H
#define AED_CLASS_HOUR_H

#include <string>
#include <vector>
#include "Lecture.h"

class Class_Hour {
public:

    std::vector<unsigned long int> students;
    std::vector<Lecture> lectures;
    std::string ucName, name;
    Class_Hour(std::string name, std::string ucName);
};


#endif