#ifndef __PET_H
#define __PET_H


#include <vector>
#include <string>

enum Type {DOG, CAT, HAMSTER};
//Create a vector to have a string representation of enum Type
const std::vector<std::string> to_string{
	"dog", "cat", "hamster"
};

class Pet{
    public:
        Pet(std::string _name, double age,Type type);     //Constructor
		std::string to_string();     //to_string method
        
    private:
       std::string _name;
       double _age;
       Type _type;



};
   
#endif
