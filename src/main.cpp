//
// Created by feld on 20-10-2022.
//

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
void menu5(Program_data& sus, request in, list<request>& failure){
    int num = in.num;
    UC* uc = in.uc;
    if(class_change::remove_Uc(sus.getStudent(num),uc)) cout << "Student removed from class successfully.";
    else{
        failure.push_back(in);
        cout << "Can't remove student from class.";
    }
}
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


int main(){

    Program_data sus = Program_data();
    Filereader::readUcs(sus);
    Filereader::readClasses(sus);
    Filereader::readStudents(sus);
    std::queue<request> requests;
    std::list<request> failedRequests;
    //cout << Timetable(*sus.getStudent(202071557));
    //READ FILES

    //cout << sus.getUC("L.EIC001")->classes.find("1LEIC02")->second->students[0] << endl;


    bool exit = false;
    while(!exit){

        std::cout << "1 Number of Students in Class/Year/UC\n2 List of Students in Class/Year/UC\n3 Student Timetable: \n4 Students with more than X UCs\n5 Remove Student from Class/UC\n" <<
        "6 Add Student to Class/UC\n7 Change Student Class\n8 Execute queued operations (5,6 and 7)\n9 List of failed operations" << std::endl;
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
            if(sus.getStudent(num)==nullptr) cout << "Student does not exist. ";
            else {
                cout << "UC Name?";
                std::string UCName = "";
                cin >> UCName;
                if (sus.getUC(UCName) == nullptr) cout << "UC does not exist. ";
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
            std::cout << "Student number or name? ";
            unsigned long int num;
            getline(cin,name);
            try{
                num=stoi(name);
            }
            catch(invalid_argument e){
                num=sus.studentNames.find(name)->second;
            }
            if(sus.getStudent(num) == nullptr) cout << "Student not found. ";
            else {
                cout << "UC Name?";
                std::string UCName = "";
                std::cin >> UCName;
                if(sus.getUC(UCName)== nullptr) cout << "Student not found. ";
                else {
                    std::cout << "Which class? ";
                    std::string className = "";
                    cin >> className;
                    if(sus.getUC(UCName)->classes.find(className)==sus.getUC(UCName)->classes.end()) cout << "Class not found. ";
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
            std::cout << "Student number or name? ";
            unsigned long int num;
            std::getline(std::cin,name);
            try{
                num=std::stoi(name);
            }
            catch(invalid_argument e){
                num=sus.studentNames.find(name)->second;
            }
            if(sus.getStudent(num)== nullptr) std::cout << "Student not found. ";
            else {
                cout << "UC Name?";
                std::string UCName = "";
                std::cin >> UCName;
                if(sus.getUC(UCName)== nullptr) std::cout<< "UC not found. ";
                else {
                    std::cout << "Which class? ";
                    std::string className = "";
                    cin >> className;
                    if(sus.getUC(UCName)->classes.find(className) == sus.getUC(UCName)->classes.end()) std::cout << "Class not found. ";
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
        else exit = true;
        if(!exit) {
            cout << "Press enter to return to menu." << std::endl;
            getline(cin, input);
            input = "";
        }
    }

    /*


    cout << endl;
    cout << Timetable(*sus.getStudent(202071557));

    class_change::remove_Uc(*sus.getStudent(202071557), sus.getUC("L.EIC023"));

    cout << endl << Timetable(*sus.getStudent(202071557));
    */
    /*
    int alunosUcTurma(string turma, string uc, map<unsigned long int, Student> students){
        int size = 0;
        std::map<unsigned long int, Student>::iterator it;
        for(it = students.begin(); it != students.end(); it++){ //students
            for(size_t i = 0; i < it->second.classes.size(); i++){
                if(it->second.classes[i]->ucName == uc && it->second.classes[i]->name == turma){
                    cout << "O aluno -" << it->first << " pertence a turma " << turma << " da uc " << uc << endl;
                    size += 1;
                }
            }
        }
        return size;
    }*/
    /*
    for(auto i : ucs){
        if(i.second.code=="L.EIC001"){
            for (auto j : i.second.classes){
                if(j.second.name=="1LEIC01") cout << Timetable(j.second);
            }
        }
    }
    */
    /*
    Program_data sus2;
    Lecture teste1("Teste","Monday",8,2,"Gay","Aula1"), teste2("FSI", "Monday",10,1,"T","Aula1");
    Lecture teste3("Canada","Tuesday",9,1,"P","Aula2");
    Lecture teste4("Albania","Tuesday",11,2,"P","Aula3");
    UC bruh1("Gay"), bruh2("Gay2");
    Class_Hour testClass("Gay","Aula1"), testClass2("Gay2","UCGay"), testClass3("Gay3","UCGay");
    Student testStudent("Canadiano",202012345);
    testClass.lectures.push_back(teste1);
    testClass.lectures.push_back(teste2);
    testClass2.lectures.push_back(teste3);
    testClass3.lectures.push_back(teste4);
    bruh1.classes.insert(std::pair<std::string,Class_Hour*>("Gay",&testClass));
    bruh2.classes.insert(std::pair<std::string,Class_Hour*>("Gay2",&testClass2));
    bruh2.classes.insert(std::pair<std::string,Class_Hour*>("Gay3",&testClass3));
    sus2.addUC(&bruh1);
    sus2.addUC(&bruh2);
    testStudent.classes.insert(std::pair<UC*,std::string>(&bruh1,"Gay"));
    testStudent.classes.insert(std::pair<UC*,std::string>(&bruh2,"Gay2"));

    std::cout << Timetable(testStudent) << std::endl;

    class_change::can_switch(&testStudent,&bruh2,"Gay3");

    std::cout << Timetable(testStudent) << std::endl;
    */

}
