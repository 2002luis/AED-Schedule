//
// Created by tomas on 28/10/2022.
//

#define maximo 25

#include "class_change.h"
#include "Class_Hour.h"
#include "Timetable.h"

#include<vector>
#include <iostream>

void class_change::remove_Uc(Student& student, UC* uc) {
    student.classes.erase(student.classes.find(uc));
}

/*Student class_change::remove_Class(Student student, UC uc) {

    Student temp = student;

    int size = temp.classes.size();

    /*for (int i = 0; i < size; i++){

        if(temp.classes[i]->name == uc.code){

            delete(temp.classes[i]); // heap memory
        }
    }

    return Student("", 0);
}
*/
void class_change::add_Uc(Student& student, UC* uc,std::string turma){

    student.classes.insert(std::pair<UC*,std::string>(uc,turma));

}


bool class_change::can_switch(Student* student, UC* uc, std::string turma) {

    Class_Hour turmaatual = *uc->classes.find(student->classes.find(uc)->second)->second;

    Class_Hour turmafutura = *uc->classes.find(turma)->second;

    Student temp = *student;

    remove_Uc(temp,uc);

    Timetable horario = Timetable(temp);

    Timetable cadeira = Timetable(*uc->classes.find(turma)->second);




    // e tamanho da propria turma
    if ( turmaatual.students.size() >= maximo) return false;

    int newmin = uc->min, newmax = uc->max;

    uc->difference();

    int diffturmaatual = turmaatual.students.size() -1;
    int diffturmafutura = turmafutura.students.size() +1;

    if(diffturmaatual < uc->min) {

        if(uc->max - diffturmaatual > 4 || diffturmafutura - diffturmaatual > 4)

            return false;

    }
    else newmin = diffturmaatual;

    if(diffturmafutura > uc->max) {

        if(uc->min + 4 >= diffturmafutura > 4 || diffturmafutura - diffturmaatual > 4)

            return false;

    }
    else newmax = diffturmafutura;

    uc->min = newmin;
    uc->max = newmax;

    if(horario.add(cadeira)) {
        remove_Uc(*student,uc);
        add_Uc(*student,uc,turma);

        Timetable horario = Timetable(*student);
        horario.add(cadeira);
        return true;
    }






    return false;
}





