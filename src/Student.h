//
// Created by luism on 18/10/2022.
//

#ifndef PROJC_STUDENT_H
#define PROJC_STUDENT_H

#include <string>
#include <vector>

#include "Class_Hour.h"
#include "Uc.h"

class Student{
    public:
        std::string name;
        unsigned long int num;
        std::map<UC*,std::string > classes; //turmas
        Student(std::string name, unsigned long int num);

    
};
#endif
