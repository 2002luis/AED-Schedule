//
// Created by tomas on 28/10/2022.
//

#ifndef SCHEDULE_CLASS_CHANGE_H
#define SCHEDULE_CLASS_CHANGE_H
#include<Student.h>
#include<Uc.h>


class class_change {
public:
    /**
        * @brief Remove os estudantes de uma turma de uma determinada UC.
        * Dá mensagem caso o aluno não esteja inscrito na cadeira.
        * Complexidade O(n)
        */
    static bool remove_Uc(Student* a , UC* b);
    /**
        * @brief Adiciona os estudantes a uma turma de uma determinada UC.
        * Dá mensagem caso o aluno já esteja numa turma dessa UC ou o horário dessa turma seja incompatível com o do aluno.
        * Complexidade O(n)
        * @param  Student* a
        * @param  UC* b
        */


    static bool add_Uc(Student* student, UC* uc,std::string turma);
    /**
       * @brief verifica se os alunos podem mudar de turma e procede a fazer essa mudança, se possível.
       * Complexidade O(n)
       * @param  Student* student
       * @param  UC* uc
       * @param  std::string turma

       */
    static bool can_switch(Student* student,UC* uc, std::string turma);
    /**
        * @brief verifica o tamanho de uma turma.
        * Complexidade O(n)
        * @param Student* student
        * @param UC* uc
        * @param  std::string turma
        */
    static bool check_size(UC* uc, std::string class1, bool add);

    /**
        * @brief Verifica o tamanho de uma turma.
        * Complexidade O(n)
        * @param  UC* uc
        * @param  std::string class1
        * @param   bool add
        */

    static bool check_size(UC* uc, std::string class1, std::string class2);

    /**
        * @brief verifica o tamanho de duas turmas.
        * Complexidade O(n)
        * @param  UC* uc
        * @param  std::string class1
        * @param  std::string class2
        */

};


#endif //SCHEDULE_CLASS_CHANGE_H
