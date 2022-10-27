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
#include <fstream>
#include <string.h>

using namespace std;


class Filereader {

public:
    Filereader();
    static std::string removeComma(std::string in);
    static map<std::string,UC> readUcs();
    static map<std::string,UC> readClasses(map<std::string, UC> in);
    static set<Student> readStudents();







};


#endif //UNTITLED_FILEREADER_H
