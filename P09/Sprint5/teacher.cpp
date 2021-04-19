#include "teacher.h"

/*
Teacher::Teacher(std::string name, std::string email)
	: _name{name}, _email{email} {}
*/
Teacher::Teacher(std::istream& ist){
	std::getline(ist, _name);
    std::getline(ist, _email);
}

void Teacher::save(std::ostream& ost) {
    Person::save(ost);
}

std::string Teacher::full_info() const {
    std::string info = Person::full_info();
    return info;
}

