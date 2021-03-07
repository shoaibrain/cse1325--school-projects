#include "student.h"
#include "parent.h"
#include <string>

//Constructor
Student::Student(std::string get_name, std::string get_email,int get_grade)
	:Person(get_name,get_email), grade(get_grade) {}
	
void Student::add_parent(Parent& parent)
{
	//pass
	
}

int Student::parents()
{
	//returns the size of vector parents
	return Student::parents.size();
}

Parent& parent (int index)
{
	//returns parent at index
	if (index < 0 || index > Student::parents.size())
		throw std::out_of_range("Invalid Index");
		
	return Student::parents[index];
}

std::string Student::full_info() const
{
	//returns everything in base class plus student's grade and parent's name
	return Student::grade + Student::parent;
}