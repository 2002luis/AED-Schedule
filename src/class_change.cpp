//
// Created by tomas on 28/10/2022.
//

#define maximo 25

#include "class_change.h"
#include "Class_Hour.h"
#include "Timetable.h"

#include<vector>
#include <iostream>

bool class_change::check_size(UC *uc, std::string class1, bool add) {
    if(add) return(class_change::check_size(uc,"",class1));
    return(class_change::check_size(uc,class1,""));
}

bool class_change::check_size(UC *uc, std::string class1, std::string class2) {

    int max = 0, min = 999;
    for(auto i : uc->classes){
        int temp = i.second->students.size();
        if(i.first==class1) temp--;
        else if(i.first==class2) temp++;

        if(temp>max) max=temp;
        else if(temp<min) min=temp;
    }

    return((max-min)<=4 && max<=maximo);
}

bool class_change::remove_Uc(Student* student, UC* uc) {

    if(!class_change::check_size(uc,student->classes.find(uc)->second,false)) return(false);

    Class_Hour* turmaatual = uc->classes.find(student->classes.find(uc)->second)->second;

    if(student->classes.find(uc)!=student->classes.end()) student->classes.erase(student->classes.find(uc));
    else{
        std::cout << "Student not in this UC" << std::endl;
        return(false);
    }



    for(unsigned long int a = 0; a < turmaatual->students.size(); a++ ){

        if(turmaatual->students[a] == student->num) {
            turmaatual->students.erase(turmaatual->students.begin() + a, turmaatual->students.begin() + a + 1);
            break;
        }
    }

    return(true);
}

bool class_change::add_Uc(Student* student, UC* uc,std::string turma){

    if(student->classes.find(uc)!=student->classes.end()) {
        std::cout << "Student already in a class in this UC.";
        return(false);
    }
    if(!class_change::check_size(uc,turma,true)) return(false);

    Timetable cur(*student), ntable(*uc->classes.find(turma)->second);
    if(!cur.add(ntable)) return(false);
    student->classes.insert(std::pair<UC*,std::string>(uc,turma));

    Class_Hour * turmaatual = uc->classes.find(student->classes.find(uc)->second)->second;

    turmaatual->students.push_back(student->num);

    return(true);
}

bool class_change::can_switch(Student *student, UC *uc, std::string turma) {

    std::string curClass = student->classes.find(uc)->second;
    if(!class_change::check_size(uc,turma,student->classes.find(uc)->second)) return(false);

    if(!class_change::remove_Uc(student,uc)) return(false);
    if(!class_change::add_Uc(student,uc,turma)){

        class_change::add_Uc(student,uc,curClass);
        return(false);
    }

    return(true);
}




