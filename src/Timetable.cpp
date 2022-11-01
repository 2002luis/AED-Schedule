//
// Created by feld on 20-10-2022.
//

#include "Timetable.h"
#include <vector>
#include <string>
#include <iostream>

Timetable::Timetable(Lecture lecture){

    std::vector<std::string> temp(30,"\t");

    for(int i = 0; i < 5; i++) this->horario.push_back(temp);

    this->horario[lecture.day][(lecture.startTime+(lecture.duration))*2-16] = "--------";

    //float halfDur = lecture.duration/2;

    this->horario[lecture.day][(lecture.startTime+(lecture.duration/2))*2-16] = lecture.toString();

    this->horario[lecture.day][(lecture.startTime)*2-16] = "--------";
}

Timetable::Timetable(Class_Hour turma){

    std::vector<std::string> temp(30,"\t");

    for(int i = 0; i < 5; i++) this->horario.push_back(temp);

    for(unsigned long int i = 0; i < turma.lectures.size(); i++){
        this->add(Timetable(turma.lectures[i]));
    }
}

Timetable::Timetable(Student student){

    std::vector<std::string> temp(30,"\t");

    for(int i = 0; i < 5; i++) this->horario.push_back(temp);

    for(auto it = student.classes.begin(); it != student.classes.end(); it++){
        auto studentClass = *it;
        UC* uc = studentClass.first;
        std::string classCode = studentClass.second;
        this->add(Timetable(*(uc->classes.find(classCode)->second)));
    }
}

bool Timetable::add(Timetable a){
    std::vector<std::string> out;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 30; j++){
            if(a.horario[i][j]!="\t" && this->horario[i][j]!="\t" && this->horario[i][j]!=a.horario[i][j]) return(false);
        }
    }
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 30; j++){
            this->horario[i][j]=max(a.horario[i][j],this->horario[i][j]);
        }
    }
    return(true);
}


