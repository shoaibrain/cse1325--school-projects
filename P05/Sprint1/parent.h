#ifndef __PARENT_H
#define __PARENT_H

#include <vector>
#include <string>
#include "person.h"


class Student;

class Parent: public Person
{	using Person::Person;
	public:
		Parent(std::string name, std::string email);
		void add_student(Student& student);
		int students();
		Student& student (int index);
		std::string full_info() const override;
		
	protected:
		std::vector<Student*> _students;
};

#endif