#ifndef __TEACHER_H
#define __TEACHER_H

#include "person.h"
#include <vector>
#include <map>



class Teacher : public Person {
  public:
	using Person::Person;
    //Teacher(std::string name, std::string email);
    Teacher(std::istream& ist);
    void save(std::ostream& ost) override;
    std::string full_info() const override;
};

#endif
