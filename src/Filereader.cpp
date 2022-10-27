#include "Filereader.h"
#include <map>
#include <string>
#include <iostream>
#include <fstream>

std::string Filereader::removeComma(std::string in){
    std::string out = "";
    for(unsigned long int i = 0; i < in.size(); i++){
        if(in[i]!=',') out+=in[i];
        else out+=' ';
    }
    return(out);
}

map<std::string,UC> Filereader::readUcs() {
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
}

map<std::string, UC> Filereader::readClasses(map<std::string, UC> in) {
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
        if(out.find(ucCode)!=out.end() && out.find(ucCode)->second.classes.find(classCode)!=out.find(ucCode)->second.classes.end())
            out.find(ucCode)->second.classes.find(classCode)->second->lectures.push_back(Lecture(classCode,day,startHour,duration,classType));
    }
    return out;
}

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
}