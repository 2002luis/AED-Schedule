//
// Created by tomas on 30/10/2022.
//

#include "Program_data.h"

#include <utility>

void Program_data::addUC(UC *uc) {
    this->UCs.insert(uc);
}

void Program_data::addStudent(Student *student) {
    this->students.insert(student);
}

UC *Program_data::getUC(std::string code) {
    UC* copy_uc = new UC(std::move(code));
    auto it = this->UCs.find(copy_uc);
    if (it != this->UCs.end()) return *it;
    return nullptr;
}

Student *Program_data::getStudent(unsigned long num) {
    auto* copy_student = new Student("", num);
    auto it = this->students.find(copy_student);
    if (it != this->students.end()) return *it;
    return nullptr;
}
