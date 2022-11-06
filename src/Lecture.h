//
// Created by luism on 18/10/2022.
//

#ifndef PROJC_LECTURE_H
#define PROJC_LECTURE_H

#include <string>

class Lecture{
    public:
        std::string classCode, ucCode;
        int day;
        float startTime, duration;
        std::string classType;
        Lecture(std::string classCode, std::string day, float startTime, float duration, std::string classType, std::string ucCode);
        /**
            * @brief Construtor do objeto Lecture(informações referentes a cada turma).
            * Complexidade O(1)
            *@param  std::string day -- dia da aula
             *@param  float startTime -- começo da aula
             *@param  float duration -- duração da aula
             *@param  std::string classType -- se a aula é T ou TP ou P
             *@param  std::string ucCode -- o código da cadeira

            */
        std::string toString();
};

#endif
