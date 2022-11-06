//
// Created by tomas on 20/10/2022.
//

#ifndef UNTITLED_FILEREADER_H
#define UNTITLED_FILEREADER_H

#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<set>
#include "Uc.h"
#include "Class_Hour.h"
#include "Lecture.h"
#include "Student.h"
#include "Program_data.h"
#include <fstream>
#include <string.h>

using namespace std;


class Filereader {

public:
    Filereader();
    static std::string removeComma(std::string in);
    /**
        * @brief Remove todas as virgulas da string que recebe .
        * std::String in -- line lida dos ficheiros .csv.
        * Complexidade O(n)
        */
    static void readUcs(Program_data& data);
    /**
        * @brief Lê as Ucs do ficheiro .csv.
        * Cria o objeto UC e guarda no set "Ucs" em Program_data,
        * Cria o objeto Class_Hour e guarda map classes da Uc.
        * Complexidade O(n)
        * @param  Program_data &data

        */
    static void readClasses(Program_data &data);
    /**
        * @brief Lê as turmas do ficheiro .csv.
        * Guarda as informações de cada turma no vector "Lectures" de cada objeto da classe "Class_hour" da respetiva Uc.
        * Complexidade O(n)
        * @param  Program_data &data
        */
    static void readStudents(Program_data &data);
    /**
        * @brief Lê os estudantes do ficheiro .csv.
        * Cria o objeto Student por estudante e adiciona no set de Program_data.
        * Insere no map classes o pointer de cada UC associado com o código da turma.
        * Para além disso também adiciona o aluno no vector "students" da classe "Class_Hour" das turmas do mesmo.
        * Complexidade O(n)
        * @param  Program_data &data .

        */
};


#endif //UNTITLED_FILEREADER_H
