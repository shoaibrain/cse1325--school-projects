#ifndef __PET_H
#define __PET_H



#include <iostream>
#include <string>
#include <exception>

using namespace std;
enum Type {DOG, CAT, HAMSTER, SNAKE,TIGER};

class Pet{
    public:
        Pet(string name, double age,Type type);     //Constructor
 
        ~Pet();                                      //Destructor
        
    private:
       string _name;
       double _age;
       Type _type;

    //to_string method
    string to_string(){

    string summary = _name+" is a " + std::to_string(_type) + " age "+std::to_string(_age);
    return summary;
};

};
   
#endif
