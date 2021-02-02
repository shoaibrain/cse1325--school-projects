#ifndef __PET_H
#define __PET_H



#include <iostream>
#include <string>

using namespace std;
enum Type {DOG, CAT, HAMSTER, SNAKE,TIGER};

class Pet{
    public:
        Pet(string _name, double _age,Type _type);     //Constructor
 
        ~Pet();                                      //Destructor

    std::string to_string();     //to_string method
        
    private:
       string _name;
       double _age;
       Type _type;



};
   
#endif
