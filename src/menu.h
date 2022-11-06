//
// Created by luism on 06/11/2022.
//

#ifndef SCHEDULE_MENU_H
#define SCHEDULE_MENU_H

#include "class_change.h"
#include "Lecture.h"
#include "Class_Hour.h"
#include "Student.h"
#include "Timetable.h"
#include "Uc.h"
#include "overloads.h"
#include "Filereader.h"
#include "Program_data.h"
#include "request.h"
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <list>
#include <algorithm>


bool sortByUCAmount(Student* student1, Student* student2);
bool sortByName(Student* student1, Student* student2);


void menu1(Program_data sus);
/**
    * @brief Conta o número de alunos em uma UC/Ano/Turma.
    * Complexidade O(n)
    * @param Program_data sus
    */
void menu2(Program_data sus);
/**
    * @brief Lista os alunos em uma UC/Ano/Turma.
    * Complexidade O(n)
    * @param Program_data sus
    */
void menu3(Program_data sus);
/**
    * @brief Imprime o horário de um aluno.
    * Complexidade O(log(n))
    * @param Program_data sus
    */
void menu4(Program_data sus);
/**
    * @brief Conta o número de alunos com mais de x UCs e imprime-os ordenados ou por número de UCs ou por nome.
    * Complexidade O(n*log(n))
    * @param Program_data sus
    */
void menu5(Program_data& sus, request in, list<request>& failure);
/**
    * @brief Remove um aluno de uma turma, se possível.
    * Complexidade O(n)
    * @param Program_data sus
    */
void menu6(Program_data& sus, request in, list<request>& failure);
/**
    * @brief Adiciona um aluno a uma turma, se possível.
    * Complexidade O(n)
    * @param Program_data sus
    */
void menu7(Program_data& sus, request in, list<request>& failure);
/**
    * @brief Troca um aluno de turma, se possível.
    * Complexidade O(n)
    * @param Program_data sus
    */
void menu10(Program_data& sus);
/**
    * @brief Escreve as informações novas dos alunos para um ficheiro.
    * Complexidade O(n)
    * @param Program_data sus
    */


#endif //SCHEDULE_MENU_H
