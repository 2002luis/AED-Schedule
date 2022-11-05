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
/*map<std::string,UC> Filereader::readUcs() {
    map<std::string,UC> out;
    std::string line;
    std::ifstream ifs("../classes_per_uc.csv");
    std::getline(ifs,line);
    while(std::getline(ifs,line)){
        line = removeComma(line);
        std::istringstream iss(line);
        std::string ucName, className;
        iss >> ucName >> className;
        if(out.find(ucName)==out.end()) out.insert(pair<std::string ,UC>(ucName,UC(ucName)));
        out.find(ucName)->second.classes.insert(pair<std::string,Class_Hour*>(className,new Class_Hour(className)));
    }
    return(out);
}*/

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

/*void Filereader::readClasses(Program_data &data) {
    map<std::string,UC> out = in;
    std::string line;
    std::ifstream ifs("../classes.csv");
    std::getline(ifs,line);
    while(std::getline(ifs,line)){
        line = removeComma(line);
        std::istringstream iss(line);
        std::string classCode, ucCode, day, classType;
        float startHour, duration;
        iss >> classCode >> ucCode >> day >> startHour >> duration >> classType;

        if(out.find(ucCode)!=out.end() && out.find(ucCode)->second.classes.find(classCode)!=out.find(ucCode)->second.classes.end()){
            UC found_uc = out.find(ucCode)->second;
            Class_Hour* classHour = found_uc.classes.find(classCode)->second;
            classHour->lectures.emplace_back(classCode,day,startHour,duration,classType);
        }
    }
    return out;
}*/



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
        //std::cout << name << '\t';
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
/*

map<unsigned long int,Student> Filereader::readStudents(map<std::string, unsigned long int> &students, map<std::string, UC> ucs) {
    map<unsigned long int, Student> out;
    std::string line;
    std::ifstream ifs("../students_classes.csv");
    std::getline(ifs,line);
    while(std::getline(ifs,line)){
        line = removeComma(line);
        std::istringstream iss(line);
        unsigned long int num;
        std::string name, ucCode, classCode;
        iss >> num >> name >> ucCode >> classCode;
        if(students.find(name)==students.end())
            students.insert(pair<std::string, unsigned long int>(name,num));
        if(out.find(num)==out.end())
            out.insert(pair<unsigned long int,Student>(num,Student(name,num)));

        //STD BAD ALLOC
        if(ucs.find(ucCode)!=ucs.end() && ucs.find(ucCode)->second.classes.find(classCode)!=ucs.find(ucCode)->second.classes.end()) {
            auto class_hour = ucs.find(ucCode)->second.classes.find(classCode)->second;
            out.find(num)->second.classes.push_back(class_hour);
        }
        //STD BAD ALLOC
    }
    return out;
}*/