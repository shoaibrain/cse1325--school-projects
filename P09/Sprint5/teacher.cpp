#include "teacher.h"

void Teacher::save(std::ostream& ost) {
    Person::save(ost);
}


std::string Teacher::full_info() const {
    std::string info = Person::full_info();
    return info;
}

