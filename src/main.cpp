//
// Created by feld on 20-10-2022.
//

#include "class_change.h"
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

    /*
    Program_data sus = Program_data();
    Filereader::readUcs(sus);
    Filereader::readClasses(sus);
    Filereader::readStudents(sus);

    cout << endl;
    cout << Timetable(*sus.getStudent(202071557));

    class_change::remove_Uc(*sus.getStudent(202071557), sus.getUC("L.EIC023"));

    cout << endl << Timetable(*sus.getStudent(202071557));
    */

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

    Program_data sus2;
    Lecture teste1("Teste","Monday",8,2,"Gay","Aula1"), teste2("FSI", "Monday",10,1,"T","Aula1");
    Lecture teste3("Canada","Tuesday",9,1,"P","Aula2");
    Lecture teste4("Albania","Tuesday",11,2,"P","Aula3");
    UC bruh1("Gay"), bruh2("Gay2");
    Class_Hour testClass("Gay","Aula1"), testClass2("Gay2","UCGay"), testClass3("Gay3","UCGay");
    Student testStudent("Canadiano",202012345);
    testClass.lectures.push_back(teste1);
    testClass.lectures.push_back(teste2);
    testClass2.lectures.push_back(teste3);
    testClass3.lectures.push_back(teste4);
    bruh1.classes.insert(std::pair<std::string,Class_Hour*>("Gay",&testClass));
    bruh2.classes.insert(std::pair<std::string,Class_Hour*>("Gay2",&testClass2));
    bruh2.classes.insert(std::pair<std::string,Class_Hour*>("Gay3",&testClass3));
    sus2.addUC(&bruh1);
    sus2.addUC(&bruh2);
    testStudent.classes.insert(std::pair<UC*,std::string>(&bruh1,"Gay"));
    testStudent.classes.insert(std::pair<UC*,std::string>(&bruh2,"Gay2"));

    std::cout << Timetable(testStudent) << std::endl;

    class_change::can_switch(&testStudent,&bruh2,"Gay3");

    std::cout << Timetable(testStudent) << std::endl;

}
