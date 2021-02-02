#include <iostream>
#include "pet.h"
#include <vector>

int main(){

    std::vector<Pet> animals;

    
    Pet p1{"Fido", 2.37, Type::DOG};
    Pet p2{"Corey", 5.6, Type::Snake};
    Pet p3{"Abby", 4.8, Type::CAT};
    Pet p4{"Matt", 7, Type::TIGER};
    Pet p5{"Jade", 1.2, Type::HAMSTER};

    animals.push_back(p1);
    animals.push_back(p2);
    animals.push_back(p3);
    animals.push_back(p4);
    animals.push_back(p5);

    for (int i = 0; i <5; i++)
    {
         std::cout << animals[i].to_string() << std::endl;
    }
    

}
