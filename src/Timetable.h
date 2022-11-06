//
// Created by feld on 20-10-2022.
//

#ifndef AED_TIMETABLE_H
#define AED_TIMETABLE_H

#include <vector>
#include "Student.h"
#include "Class_Hour.h"
#include "Lecture.h"

class Timetable {
    public:
        std::vector<std::vector<std::string>> horario;
        Timetable(Lecture lecture);
        /**
            * @brief Cria o horário de uma aula.
            * Complexidade O(1)
            * @param  Lecture lecture

            */
        Timetable(Class_Hour turma); //class é uma palavra reservada
        /**
            * @brief Cria o horário de uma turma a partir dos horários das suas aulas.
            * Complexidade O(n)
            * @param  Class_Hour turma

            */
        Timetable(Student student);
        /**
            * @brief Cria o horário de um aluno a partir dos horários das suas turmas.
            * Complexidade O(n)
            * @param  Student student

            */
        bool add(const Timetable a);
        /**
            * @brief Verifica se 2 horários são compatíveis para ser somados. Se forem, soma e dá return true. Se não forem, dá return false.
            * Complexidade O(n)
            * @param  Timetable a

            */
};


#endif

