//
// Created by luism on 18/10/2022.
//

#ifndef PROJC_LECTURE_H
#define PROJC_LECTURE_H

#include <string>

class Lecture{
    public:
        std::string classCode, ucCode;
        int day;
        float startTime, duration;
        std::string classType;
        Lecture(std::string classCode, std::string day, float startTime, float duration, std::string classType, std::string ucCode);
        std::string toString();
};

#endif
