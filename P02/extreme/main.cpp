#include "pet.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

bool less_than(Pet p1, Pet p2){
	return p1.pet_years() < p2.pet_years();
}

int main(){

    std::vector<Pet> pets{
		Pet{"Fido",3,CAT},
		Pet{"Corey",2,DOG},
		Pet{"Jackie",1,HAMSTER},
	};
	std::sort(pets.begin(), pets.end(), less_than);
    for (Pet& p:pets) std::cout <<p.to_string() << std::endl;

}
