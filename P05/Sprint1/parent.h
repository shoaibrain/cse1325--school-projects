#ifndef __PARENT_H
#define __PARENT_H

#include <vector>
#inclide <string>

Student Student;

class Parent: public Person
{	using Person::Person;
	public:
		Parent(std::strig name, std::string email);
		void add_student(Student& student);
		int students();
		Student& student (int index);
		std::string full_info() const override;
		
	protected:
		std::vector<Student*> students;
}

#endif