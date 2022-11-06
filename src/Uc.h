//
// Created by up202005832 on 17/10/2022.
//

#ifndef MRDS_UC_H
#define MRDS_UC_H

#include <string.h>
#include <vector>

#include "Class_Hour.h"
#include <map>

class UC{ // passa a ter um vetor de turmas , class turmas
public:
    UC(std::string code);
    std::string name;
    std::map<std::string,Class_Hour*> classes;
    bool operator<(UC);
    unsigned char max;
    unsigned char min;
};



#endif