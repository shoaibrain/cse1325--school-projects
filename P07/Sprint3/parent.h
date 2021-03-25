#ifndef __PARENT_H
#define __PARENT_H

#include "person.h"
#include <vector>

class Student;

class Parent : public Person {
  public:
    using Person::Person;
	Parent(std::string name, std::string email);
    void add_student(Student& student);
	Parent(std::istream& ist); //Open previously saved Parent
	virtual void save(std::ostream& ost) override; //Save the parent
    int students();
    Student& student(int index);
    std::string full_info() const override;
  private:
    std::vector<Student*> _students;
};

#endif
