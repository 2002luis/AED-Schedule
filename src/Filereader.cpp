#include "Filereader.h"
#include <map>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

std::string Filereader::removeComma(std::string in){
    std::string out = in;
    while(out.find(' ')!=std::string::npos) out[out.find(' ')]='_';
    while(out.find(',')!=std::string::npos) out[out.find(',')]=' ';
    return(out);
}


void Filereader::readUcs(Program_data& data) {
    string line;
    std::ifstream ifs("../classes_per_uc.csv");
    std::getline(ifs,line);
    while(std::getline(ifs,line)){
        line = removeComma(line);
        std::istringstream iss(line);
        std::string ucName, className;
        iss >> ucName >> className;
        auto uc = data.getUC(ucName);

        if (uc == nullptr) {
            uc = new UC(ucName);
            data.addUC(uc);
        }
        uc->classes.insert(pair<std::string,Class_Hour*>(className,new Class_Hour(className, ucName)));
    }
}

void Filereader::readClasses(Program_data &data) {
    std::string line;
    std::ifstream ifs("../classes.csv");
    std::getline(ifs,line);
    while(std::getline(ifs,line)) {
        line = removeComma(line);
        std::istringstream iss(line);
        std::string classCode, ucCode, day, classType;
        float startHour, duration;
        iss >> classCode >> ucCode >> day >> startHour >> duration >> classType;
        auto uc = data.getUC(ucCode);
        if (uc == nullptr) continue;
        auto it = uc->classes.find(classCode);

        if (it == uc->classes.end()) continue;

        Class_Hour* classHour = it->second;

        if (classHour == nullptr) continue;

        classHour->lectures.emplace_back(classCode,day,startHour,duration,classType, ucCode);


    }



}

void Filereader::readStudents(Program_data& data) {

    std::string line;
    std::ifstream ifs("../students_classes.csv");
    std::getline(ifs, line);
    while (std::getline(ifs, line)) {
        line = removeComma(line);
        std::istringstream iss(line);
        unsigned long int num;
        std::string name, ucCode, classCode;
        iss >> num >> name >> ucCode >> classCode;
        if(name.find('_')!=std::string::npos) name[name.find('_')] = ' ';
        auto student = data.getStudent(num);
        if (student == nullptr) {
            student = new Student(name, num);
            data.addStudent(student);
        }
        auto uc = data.getUC(ucCode);

        if (uc == nullptr) continue;

        student->classes.insert(pair<UC *, string>(uc, classCode));
        data.getUC(ucCode)->classes.find(classCode)->second->students.push_back(num);

    }
}
