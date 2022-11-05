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

    UC ucNova = *uc;
    if(class1!="") ucNova.classes.find(class1)->second->students.erase(ucNova.classes.find(class1)->second->students.begin(),ucNova.classes.find(class1)->second->students.begin()+1);
    if(class2!="") ucNova.classes.find(class2)->second->students.push_back(21);

    return(ucNova.difference()<=4);
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
void class_change::remove_Class(Student* student) {
    std::map<UC*, std::string>::iterator it = student->classes.begin();
    for( it; it != student->classes.end(); it++ ){
        remove_Uc(student,it->first);
    }
}
//void class_change::add_Class(Student* student,std::string turma, Program_data a){
//}
bool class_change::can_switch(Student *student, UC *uc, std::string turma) {

    if(!class_change::check_size(uc,turma,student->classes.find(uc)->second)) return(false);
    class_change::remove_Uc(student,uc);
    class_change::add_Uc(student,uc,turma);
    /*
    Class_Hour turmafutura = *uc->classes.find(turma)->second;

    Student temp = *student;

    Timetable horario = Timetable(temp);

    if(temp.classes.find(uc)!=temp.classes.end()) remove_Uc(temp,uc);

    Timetable cadeira = Timetable(*uc->classes.find(turma)->second);
    // e tamanho da propria turma
    if ( turmaatual.students.size() >= maximo) return false;
    int newmin = uc->min, newmax = uc->max;
    uc->difference();
    int diffturmaatual = turmaatual.students.size() -1;
    int diffturmafutura = turmafutura.students.size() +1;
    if(diffturmaatual < uc->min) {
        if(uc->max - diffturmaatual > 4 || diffturmafutura - diffturmaatual > 4)
            return false; }
    else newmin = diffturmaatual;
    if(diffturmafutura > uc->max) {
        if(uc->min + 4 >= diffturmafutura > 4 || diffturmafutura - diffturmaatual > 4)
            return false; }
    else newmax = diffturmafutura;
    uc->min = newmin;
    uc->max = newmax;
    if(horario.add(cadeira)) {
        remove_Uc(*student,uc);
        add_Uc(student,uc,turma);
        Timetable horario = Timetable(*student);
        horario.add(cadeira);
        return true;}
    return false;
     */
    return(true);
}




