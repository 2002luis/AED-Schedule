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

    public:
        std::set<UC*,UCcomparator> UCs;
        std::set<Student*,Studentcomparator> students;
        std::map<std::string, unsigned long int> studentNames;

        void addUC(UC* uc);
        /**
            * @brief Adiciona um objeto Uc ao set UCs.
            * Complexidade O(log(n))
            *@param  UC* uc -- pointer para o objeto uc

            */
        void addStudent(Student* student);
        /**
           * @brief Adiciona um objeto Student ao set students.
           * Insere o nome e numero do estudante no mapa studentNames
           * Complexidade O(log(n))
           *@param  Student* student -- pointer para o objeto student

           */
        UC* getUC(std::string code);
        /**
            * @brief Procura e retorna a UC guardada no set.
            * Se não encontrar retorna nullpointer
            * Complexidade O(log(n))
            *@param  std::string code -- código da Uc

            */
        Student* getStudent(unsigned long int num);
        /**
            * @brief Procura e retorna o Student guardado no set.
            * se não encontrar o Student retorna nullpointer
            * Complexidade O(log(n))
            *@param  unsigned long int num -- número do aluno

            */
        Student* getStudent(std::string name);
};


#endif //SCHEDULE_PROGRAM_DATA_H
