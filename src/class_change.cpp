//
// Created by tomas on 28/10/2022.
//

#include "class_change.h"
#include "Class_Hour.h"
#include "Timetable.h"

#include<vector>

Student class_change::remove_Uc(Student student, UC uc) {

    int size = student.classes.size();



    /*for (int i = 0; i < size; i++){

        if(student.classes[i]->name == uc.code){

            delete(student.classes[i]); // heap memory
        }
    }*/
    return Student("", 0);
}

Student class_change::remove_Class(Student student, UC uc) {

    Student temp = student;

    int size = temp.classes.size();

    /*for (int i = 0; i < size; i++){

        if(temp.classes[i]->name == uc.code){

            delete(temp.classes[i]); // heap memory
        }
    }*/

    return Student("", 0);
}
/*
bool class_change::can_switch(Student student, UC uc, Turma turma) {

    Timetable horario = Timetable(remove_Class(student,uc));

    Timetable horario_uc = Timetable(*uc.classes.find("leic")->second);


        // e tamanho da propria turma
    if ( turma.size() >= 25){

        return false;
    }
    if(horario.add(horario_uc)){

        Timetable thorario = Timetable(remove_Uc(student,uc));

        thorario.add(horario_uc);

        return true;
    }

    return false;
}*/





