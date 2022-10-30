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
#include "Program_data.h"
#include <iostream>
#include <vector>
#include <set>
#include <map>







int main(){

    Program_data sus = Program_data();
    Filereader::readUcs(sus);
    Filereader::readClasses(sus);
    Filereader::readStudents(sus);

    cout << Timetable(*sus.getStudent(202071557));
    /*
    int alunosUcTurma(string turma, string uc, map<unsigned long int, Student> students){
        int size = 0;
        std::map<unsigned long int, Student>::iterator it;
        for(it = students.begin(); it != students.end(); it++){ //students
            for(size_t i = 0; i < it->second.classes.size(); i++){
                if(it->second.classes[i]->ucName == uc && it->second.classes[i]->name == turma){
                    cout << "O aluno -" << it->first << " pertence a turma " << turma << " da uc " << uc << endl;
                    size += 1;
                }
            }
        }
        return size;
    }*/
    /*
    for(auto i : ucs){
        if(i.second.code=="L.EIC001"){
            for (auto j : i.second.classes){
                if(j.second.name=="1LEIC01") cout << Timetable(j.second);
            }
        }
    }
    */

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
