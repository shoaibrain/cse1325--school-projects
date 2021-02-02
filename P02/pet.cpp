#include "pet.h"
#include <iostream>
#include <string>
using namespace std;

int Pet::Pet(string name, double age,Type type):_name{name},_age{age},_type{type}{

}

Pet::~Pet(){}

std::string Pet::to_string(string name,double age, Type type){
    string summary = name+" is a "+ std::to_string(type) + " age "+ std::to_string(age);
    return summary;
};

