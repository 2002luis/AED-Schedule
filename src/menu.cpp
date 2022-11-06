//
// Created by luism on 06/11/2022.
//

#include "menu.h"
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

bool sortByUCAmount(Student* student1, Student* student2){
    return(student1->classes.size()<student2->classes.size());
}
bool sortByName(Student* student1, Student* student2){
    return(student1->name<student2->name);
}


void menu1(Program_data sus){
    int out = 0;
    std::cout << "Class (1), Year (2) or UC(3)?";
    std::string num = ""; //1 Turma 2 Ano 3 UC
    while(num!="1" && num!="2" && num!="3") std::cin >> num;
    if(num=="1"){
        std::string ucName, className;
        std::cout << "UC Name?";
        std::cin >> ucName;
        UC* uc = sus.getUC(ucName);
        if(uc == nullptr) {
            std::cout << "UC does not exist." << std::endl;
            return;
        }
        std::cout << "Class Name?";
        std::cin >> className;
        std::cout << std::endl;
        Class_Hour turma("lixo","lixo");
        if(uc->classes.end()!=uc->classes.find(className)) turma = *uc->classes.find(className)->second;
        else return;
        for(unsigned long int i = 0; i < turma.students.size(); i++){
            out++;
        }
    }
    else if(num=="2"){
        int n;
        while (true) {
            std::cout << "Student year:";
            std::cin >> n;
            std::cout << std::endl;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Not a number! " << endl;
            } else break;
        }
        for(auto i : sus.students) if(i->num/100000 == n) {
                out++;
            }
    }
    else{
        std::cout << "UC Name?";
        std::cin >> num;
        UC* uc=sus.getUC(num);
        if(uc == nullptr){
            std::cout << "UC does not exist." << std::endl;
            return;
        }
        for(auto i : sus.students){
            out++;
        }
    }
    std::cout << "Total: " << out << std::endl;
}
/**
    * @brief Conta o número de alunos em uma UC/Ano/Turma.
    * Complexidade O(n)
    */
void menu2(Program_data sus){
    cout << "Class (1), Year (2) or UC(3)?";
    std::string num = ""; //1 Turma 2 Ano 3 UC
    while(num!="1" && num!="2" && num!="3") cin >> num;
    if(num=="1"){
        std::string ucName, className;
        std::cout << "UC Name?";
        std::cin >> ucName;
        UC* uc = sus.getUC(ucName);
        if(uc == nullptr) {
            std::cout << "UC does not exist." << std::endl;
            return;
        }
        std::cout << "Class Name?";
        std::cin >> className;
        std::cout << std::endl;
        Class_Hour turma("lixo","lixo");
        if(uc->classes.end()!=uc->classes.find(className)) turma = *uc->classes.find(className)->second;
        else return;
        for(unsigned long int i = 0; i < turma.students.size(); i++){
            Student student = *sus.getStudent(turma.students[i]);
            std::cout << student.name << " " << student.num << std::endl;
        }
    }
    else if(num=="2"){
        int n;
        while (true) {
            std::cout << "Student year:";
            std::cin >> n;
            std::cout << std::endl;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Not a number! " << endl;
            } else break;
        }
        for(auto i : sus.students) if(i->num/100000 == n) {
                std::cout << i->name << " " << i->num << std::endl;
            }
    }
    else{
        std::cout << "UC Name?";
        std::cin >> num;
        UC* uc=sus.getUC(num);
        if(uc == nullptr){
            std::cout << "UC does not exist." << std::endl;
            return;
        }
        for(auto i : sus.students){
            if(i->classes.find(uc)!=i->classes.end()) cout << i->name << " " << i->num << std::endl;
        }
    }
}
/**
    * @brief Lista os alunos em uma UC/Ano/Turma.
    * Complexidade O(n)
    */
void menu3(Program_data sus){
    unsigned long int num;
    std::string name;
    std::cout << "Student number or name? ";
    getline(cin,name);
    try{
        num=stoi(name);
    }
    catch(invalid_argument e){
        num=sus.studentNames.find(name)->second;
    }
    Student* student = sus.getStudent(num);
    if(student!= nullptr) std::cout << std::endl << Timetable(*student);
    else std::cout << "Student not found!" << std::endl;
}
/**
    * @brief Imprime o horário de um aluno.
    * Complexidade O(log(n))
    */
void menu4(Program_data sus){
    int n;
    std::vector<Student*> out;
    while (true) {
        std::cout << "Number of UCs: ";
        std::cin >> n;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore();
            cout << "Not a number! " << endl;
        } else break;
    }
    for(auto i : sus.students){
        if(i->classes.size()>n) out.push_back(i);
    }

    std::cout << out.size() << " students were found. ";
    std::cout << "Sort by alphabetical order (1) or number of UCs (2)?";

    std::string sortType="";
    cin >> sortType;
    while(sortType!="1" && sortType!="2" && sortType!="alpha" && sortType!="UC" && sortType!="UCs"){
        cout << "Invalid input. ";
        cin >> sortType;
    }
    if(sortType=="1" || sortType == "alpha") sort(out.begin(), out.end(), sortByName);
    else sort(out.begin(), out.end(), sortByUCAmount);

    for(auto i : out){
        std::cout << i->num << ' ' << i->name << ' ' << i->classes.size() << std::endl;
    }
}
/**
    * @brief Conta o número de alunos com mais de x UCs e imprime-os ordenados ou por número de UCs ou por nome.
    * Complexidade O(n*log(n))
    */
void menu5(Program_data& sus, request in, list<request>& failure){
    int num = in.num;
    UC* uc = in.uc;
    if(class_change::remove_Uc(sus.getStudent(num),uc)) cout << "Student removed from class successfully.";
    else{
        failure.push_back(in);
        cout << "Can't remove student from class.";
    }
}
/**
    * @brief Remove um aluno de uma turma, se possível.
    * Complexidade O(n)
    */
void menu6(Program_data& sus, request in, list<request>& failure){
    int num = in.num;
    UC* uc = in.uc;
    std::string className = in.destination;
    if(class_change::add_Uc(sus.getStudent(num),uc,className)) cout << "Student added to class successfully.";
    else {
        failure.push_back(in);
        std::cout << "Couldn't add student to class.";
    }
}
/**
    * @brief Adiciona um aluno a uma turma, se possível.
    * Complexidade O(n)
    */
void menu7(Program_data& sus, request in, list<request>& failure){
    int num = in.num;
    UC* uc = in.uc;
    std::string className = in.destination;
    if(class_change::can_switch(sus.getStudent(num),uc,className)) cout << "Student added to class successfully. ";
    else {
        failure.push_back(in);
        cout << "Couldn't add student to class. ";
    }
}
/**
    * @brief Troca um aluno de turma, se possível.
    * Complexidade O(n)
    */
void menu10(Program_data& sus){
    remove("../students_classes.csv");
    std::ofstream ofs("../students_classes.csv");
    ofs << "StudentCode,StudentName,UcCode,ClassCode";
    for(auto i : sus.students){
        for(auto j : i->classes){
            ofs << std::endl << i->num << ',' << i->name << ',' << j.first->name << ',' << j.second;
        }
    }
}
/**
    * @brief Escreve as informações novas dos alunos para um ficheiro.
    * Complexidade O(n)
    */