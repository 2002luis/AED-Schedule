//
// Created by feld on 20-10-2022.
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




int main(){

    Program_data sus = Program_data();
    Filereader::readUcs(sus);
    Filereader::readClasses(sus);
    Filereader::readStudents(sus);
    std::queue<request> requests;
    std::list<request> failedRequests;


    bool exit = false;
    while(!exit){

        std::cout << "1 Number of Students in Class/Year/UC\n2 List of Students in Class/Year/UC\n3 Student Timetable \n4 Students with more than X UCs\n5 Remove Student from Class/UC\n" <<
        "6 Add Student to Class/UC\n7 Change Student Class\n8 Execute queued operations (5,6 and 7)\n9 List of failed operations\n10 Write to file" << std::endl;
        std::string input;
        std::cin >> input;
        getchar(); //CATCH \n
        // 1 merdas
        // 2 horário de estudante x
        // 3 estudantes em turma/ano/UC
        // 4 estudantes com mais de X UCs
        // 5 remover aluno de turma/UC
        // 6 adicionar aluno a turma/UC
        // 7 alterar turma
        // 8 fazer as coisas na fila
        // 9 ver lista de coisas falhadas
        // 10 escrever
        if(input=="1"){
            menu1(sus);
        }
        else if(input=="2"){
            menu2(sus);
        }
        else if(input=="3"){
            menu3(sus);
        }
        else if(input=="4"){
            menu4(sus);
        }
        else if(input=="5"){
            std::string name = "";
            std::cout << "Student number or name?";
            unsigned long int num;
            getline(cin,name);
            try{
                num=stoi(name);
            }
            catch(invalid_argument e){
                num=sus.studentNames.find(name)->second;
            }
            if(sus.getStudent(num)==nullptr) cout << "Student does not exist.";
            else {
                cout << "UC Name?";
                std::string UCName = "";
                cin >> UCName;
                if (sus.getUC(UCName) == nullptr) cout << "UC does not exist.";
                else {
                    request newRequest;
                    newRequest.num = num;
                    newRequest.operation = 5;
                    newRequest.uc = sus.getUC(UCName);
                    newRequest.destination = "";
                    requests.push(newRequest);
                }
            }
        }
        else if(input=="6"){
            std::string name = "";
            std::cout << "Student number or name?";
            unsigned long int num;
            getline(cin,name);
            try{
                num=stoi(name);
            }
            catch(invalid_argument e){
                num=sus.studentNames.find(name)->second;
            }
            if(sus.getStudent(num) == nullptr) cout << "Student not found.";
            else {
                cout << "UC Name?";
                std::string UCName = "";
                std::cin >> UCName;
                if(sus.getUC(UCName)== nullptr) cout << "Student not found.";
                else {
                    std::cout << "Which class? ";
                    std::string className = "";
                    cin >> className;
                    if(sus.getUC(UCName)->classes.find(className)==sus.getUC(UCName)->classes.end()) cout << "Class not found.";
                    else {
                        request newRequest;
                        newRequest.num = num;
                        newRequest.operation = 6;
                        newRequest.uc = sus.getUC(UCName);
                        newRequest.destination = className;
                        requests.push(newRequest);
                    }
                }
            }
        }
        else if(input=="7"){
            std::string name = "";
            std::cout << "Student number or name?";
            unsigned long int num;
            std::getline(std::cin,name);
            try{
                num=std::stoi(name);
            }
            catch(invalid_argument e){
                num=sus.studentNames.find(name)->second;
            }
            if(sus.getStudent(num)== nullptr) std::cout << "Student not found.";
            else {
                cout << "UC Name?";
                std::string UCName = "";
                std::cin >> UCName;
                if(sus.getUC(UCName)== nullptr) std::cout<< "UC not found.";
                else {
                    std::cout << "Which class? ";
                    std::string className = "";
                    cin >> className;
                    if(sus.getUC(UCName)->classes.find(className) == sus.getUC(UCName)->classes.end()) std::cout << "Class not found.";
                    else {
                        request newRequest;
                        newRequest.num = num;
                        newRequest.operation = 7;
                        newRequest.uc = sus.getUC(UCName);
                        newRequest.destination = className;
                        requests.push(newRequest);
                    }
                }
            }
        }

        else if(input=="8"){
            while(requests.size()>0){
                request cur = requests.front();
                requests.pop();
                if(cur.operation==5) menu5(sus,cur,failedRequests);
                else if(cur.operation==6) menu6(sus,cur,failedRequests);
                else if(cur.operation==7) menu7(sus,cur,failedRequests);
            }
            std::cout << std::endl;
        }
        else if(input=="9"){
            for(auto i : failedRequests){
                if(i.operation!=5) cout << "Couldn't add student " << i.num << "to class " << i.destination << "of UC " << i.uc->name << std::endl;
                else cout << "Couldn't remove student " << i.num << "from class " << i.destination << "of UC " << i.uc->name << std::endl;
            }
        }

        else if(input=="10"){
            menu10(sus);
        }
        else exit = true;
        if(!exit) {
            cout << "Press enter to return to menu." << std::endl;
            getline(cin, input);
            input = "";
        }
    }

}
