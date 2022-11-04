//
// Created by luism on 04/11/2022.
//

#ifndef SCHEDULE_REQUEST_H
#define SCHEDULE_REQUEST_H

#include "Uc.h"
#include <string>

struct request{
    unsigned long int num = 0;
    int operation = 0;
    std::string destination = "";
    UC* uc = nullptr;
};

#endif //SCHEDULE_REQUEST_H
