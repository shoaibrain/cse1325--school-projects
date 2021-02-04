#include "pet.h"
#include <iostream>
#include <iomanip>
#include <vector>


int main(){

    std::vector<Pet> pets{
		Pet{"Fido",3,CAT},
		Pet{"Corey",2,DOG},
		Pet{"Jackie",1,HAMSTER},
	};


    for (Pet& p:pets) std::cout <<p.to_string() << std::endl;

}
