//
// Created by luism on 18/10/2022.
//
#include <string>
#include "Uc.h"

UC::UC(std::string code){
    this->name= code;
}

int UC::difference() {

    for(auto i : classes){

        unsigned char num =  i.second->students.size();

        if(num < min) { this->min = num;}

        if(num > max) {this->max = num;}
    }

    return(max-min);

}