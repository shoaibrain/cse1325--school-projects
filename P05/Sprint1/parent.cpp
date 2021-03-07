#include "parent.h"
#include "student.h"
#include <string>

//Constructor
Parent::Parent(std::string get_name, std::string get_email)
	:Person(get_name,get_email), grade(get_grade) {}
	
void Parent::add_student(Student& student)
{
		//pass
		
}

int Parent::students()
{
	//returns the size of vector parents
	return Parent::students.size();
}

Student& student:: (int index)
{
	//returns parent at index
	if (index < 0 || index > Parent::students.size())
		throw std::out_of_range("Invalid Index");
		
	return Parent::students[index];
}

std::string Parent::full_info() const
{
	//returns everything in base class plus parent's student (students under parent)
	return Parent::students;
}