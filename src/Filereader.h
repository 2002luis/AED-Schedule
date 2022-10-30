//
// Created by tomas on 20/10/2022.
//

#ifndef UNTITLED_FILEREADER_H
#define UNTITLED_FILEREADER_H

#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<set>
#include "Uc.h"
#include "Class_Hour.h"
#include "Lecture.h"
#include "Student.h"
#include "Program_data.h"
#include <fstream>
#include <string.h>

using namespace std;


class Filereader {

public:
    Filereader();
    static std::string removeComma(std::string in);
    static void readUcs(Program_data& data);
    static void readClasses(Program_data &data);
    static void readStudents(Program_data &data);
};


#endif //UNTITLED_FILEREADER_H
