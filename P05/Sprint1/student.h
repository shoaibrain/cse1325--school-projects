#ifndef __STUDENT_H
#define __STUDENT_H


#include <string>
#include <vector>
#include "person.h"


class Parent;

class Student: public Person {
	using Person::Person;
	public:
		Student(std::string name, std::string email,int grade);  //Constructor
		void add_parent(Parent& parent);    //add 
		int parents();             //number of parent 
		Parent& parent(int index);
		std::string full_info() const override;
	protected:
		int grade;
		std::vector<Parent*> _parents;

		
};

#endif