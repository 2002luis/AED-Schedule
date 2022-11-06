#include "Filereader.h"
#include <iostream>

std::string Lecture::toString() {
    return this->ucCode + " " + this->classType;
}

Lecture::Lecture(std::string classCode, std::string day, float startTime, float duration, std::string classType, std::string ucCode) {
    this->ucCode = ucCode;
    this->classCode=classCode;
    this->startTime=startTime;
    this->duration=duration;
    this->classType=classType;
    if(day == "Monday") this->day = 0;
    else if(day == "Tuesday") this->day = 1;
    else if(day == "Wednesday") this->day = 2;
    else if(day == "Thursday") this->day = 3;
    else this->day = 4;
}