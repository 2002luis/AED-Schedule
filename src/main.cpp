//
// Created by feld on 20-10-2022.
//

#include "Lecture.h"
#include "Class_Hour.h"
#include "Student.h"
#include "Timetable.h"
#include "Uc.h"
#include "overloads.h"
#include "Filereader.h"
#include <iostream>
#include <vector>
#include <set>
#include <map>







int main(){
    std::map<std::string,UC> ucs = Filereader::readClasses(Filereader::readUcs());


    for(auto i : ucs){
        if(i.second.code=="L.EIC001"){
            for (auto j : i.second.classes){
                if(j.second.name=="1LEIC01") cout << Timetable(j.second);
            }
        }
    }


/*
    Lecture teste1("Teste","Monday",8,2,"Gay"), teste2("FSI", "Monday",10,1,"T");
    Lecture teste3("Canada","Tuesday",9,1,"P");
    Class_Hour testClass("Gay"), testClass2("Gay2");
    Student testStudent("Canadiano",202012345);
    testClass.lectures.push_back(teste1);
    testClass.lectures.push_back(teste2);
    testClass2.lectures.push_back(teste3);
    testStudent.classes.push_back(&testClass);
    testStudent.classes.push_back(&testClass2);
    std::cout << Timetable(testStudent) << std::endl;
*/
}
