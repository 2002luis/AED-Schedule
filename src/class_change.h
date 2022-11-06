//
// Created by tomas on 28/10/2022.
//

#ifndef SCHEDULE_CLASS_CHANGE_H
#define SCHEDULE_CLASS_CHANGE_H
#include<Student.h>
#include<Uc.h>


class class_change {
public:
    static bool remove_Uc(Student* , UC*);
    static bool add_Uc(Student* student, UC* uc,std::string turma);
    static bool can_switch(Student*,UC*, std::string);
    static bool check_size(UC* uc, std::string class1, bool add);
    static bool check_size(UC* uc, std::string class1, std::string class2);

};


#endif //SCHEDULE_CLASS_CHANGE_H
