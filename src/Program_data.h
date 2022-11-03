//
// Created by tomas on 30/10/2022.
//

#ifndef SCHEDULE_PROGRAM_DATA_H
#define SCHEDULE_PROGRAM_DATA_H


#include <set>
#include "Uc.h"
#include "Student.h"

struct UCcomparator {

    bool operator()(UC* uc1,UC* uc2) const{
        return uc1->name < uc2->name;
    }

};

struct Studentcomparator {

    bool operator()(Student* student1, Student* student2) const{
        return student1->num < student2->num;
    }
};

class Program_data {

    private:
        std::set<UC*,UCcomparator> UCs;
        std::set<Student*,Studentcomparator> students;

    public:
        void addUC(UC* uc);
        void addStudent(Student* student);

        UC* getUC(std::string code);
        Student* getStudent(unsigned long int num);
};


#endif //SCHEDULE_PROGRAM_DATA_H
