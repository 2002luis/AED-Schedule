//
// Created by tomas on 28/10/2022.
//

#ifndef SCHEDULE_CLASS_CHANGE_H
#define SCHEDULE_CLASS_CHANGE_H
#include<Student.h>
#include<Uc.h>


class class_change {
public:
    static void remove_Uc(Student& , UC*);
    static void remove_Class(Student*);
    static void add_class();
    static bool add_Uc(Student* student, UC* uc,std::string turma);
    static bool can_switch(Student*,UC*, std::string);

};


#endif //SCHEDULE_CLASS_CHANGE_H
