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
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stdlib.h>
#include <algorithm>

bool sortByUCAmount(Student* student1, Student* student2){
    return(student1->classes.size()<student2->classes.size());
}

bool sortByName(Student* student1, Student* student2){
    return(student1->name<student2->name);
}

void menu2(Program_data sus){
    unsigned long int num;
    std::string name;
    int n;
    std::cout << "Student number (1) or name (2)? ";
    std::cin >> n;
    if(n==1) std::cin >> num;
    else {
        std::cin >> name;
        num = sus.studentNames.find(name)->second;
    }
    Student* student = sus.getStudent(num);
    if(student!= nullptr) std::cout << std::endl << Timetable(*student);
    else std::cout << "Student not found!" << std::endl;
}
void menu3(Program_data sus){
    int out = 0;
    string num = ""; //1 Turma 2 Ano 3 UC
    while(num!="1" && num!="2" && num!="3") cin >> num;
    if(num=="1"){
        string ucName;
        cout << "UC Name? ";
        cin >> ucName;
        cout << "Class Name? ";
        cin >> num;
        UC uc = *sus.getUC(ucName);
        Class_Hour turma = *uc.classes.find(num)->second;
        out = turma.students.size();
    }
    if(num=="2"){
        int n;

        while (true) {
            std::cout << "Student year: ";
            std::cin >> n;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore();
                cout << "Not a number! " << endl;
            } else break;
        }
        for(auto i : sus.students) if(i->num/100000 == n) out++;


    }
    else{
        cin >> num;
        UC uc=*sus.getUC(num);
        cin >> num;
        for(auto i : sus.students){
            if(i->classes.find(&uc)!=i->classes.end()) out++;
        }
    }
    std::cout << out;
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
void menu5(Program_data& sus){

    std::string in = "";


    unsigned long int num;
    string name;
    cout << "Student number (1) or name (2)? ";
    cin >> num;
    if(num==1) cin >> num;
    else {
        cin >> name;
        num = sus.studentNames.find(name)->second;
    }
    cout << "UC Name?";
    std::string UCName = "";
    cin >> UCName;
    class_change::remove_Uc(*sus.getStudent(num),sus.getUC(UCName));
}
void menu6(Program_data& sus){
    unsigned long int num;
    string name;
    cout << "Student number (1) or name (2)? ";
    cin >> num;
    if(num==1) cin >> num;
    else {
        cin >> name;
        num = sus.studentNames.find(name)->second;
    }
    cout << "UC Name?";
    std::string UCName = "";
    std::cin >> UCName;
    std::cout << "Which class? ";
    std::string className = "";
    cin >> className;
    if(class_change::add_Uc(sus.getStudent(num),sus.getUC(UCName),className)) cout << "Student added to class successfully. ";
    else cout << "Couldn't add student to class. ";
}
void menu7(Program_data& sus){
    unsigned long int num;
    string name;
    cout << "Student number (1) or name (2)? ";
    cin >> num;
    if(num==1) cin >> num;
    else {
        cin >> name;
        num = sus.studentNames.find(name)->second;
    }
    cout << "UC Name?";
    std::string UCName = "";
    std::cin >> UCName;
    std::cout << "Which class? ";
    std::string className = "";
    cin >> className;
    std::string oldClassName = sus.getStudent(num)->classes.find(sus.getUC(UCName))->second;
    Timetable oldClass(*sus.getUC(UCName)->classes.find(className)->second);
    class_change::remove_Uc(*sus.getStudent(num),sus.getUC(UCName));
    if(class_change::add_Uc(sus.getStudent(num),sus.getUC(UCName),className)) cout << "Student added to class successfully. ";
    else {

        cout << "Couldn't add student to class. ";
    }
}


int main(){

    Program_data sus = Program_data();
    Filereader::readUcs(sus);
    Filereader::readClasses(sus);
    Filereader::readStudents(sus);

    cout << Timetable(*sus.getStudent(202071557));
    //READ FILES

    bool exit = false;
    while(!exit){

        std::cout << "Programa gay: ";
        std::string input;
        std::cin >> input;
        // 1 merdas
        // 2 horário de estudante x
        // 3 estudantes em turma/ano/UC
        // 4 estudantes com mais de X UCs
        // 5 remover aluno de turma/UC
        // 6 adicionar aluno a turma/UC
        // 7 alterar turma
        if(input=="1"){}
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
            menu5(sus);
        }
        else if(input=="6"){
            menu6(sus);
        }
        else if(input=="7"){
            menu7(sus);
        }
        else exit = true;
        getchar();
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
