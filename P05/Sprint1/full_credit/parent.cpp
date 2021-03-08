#include "parent.h"
#include "student.h"
#include <string>

//Constructor
Parent::Parent(std::string get_name, std::string get_email)
	:Person(get_name,get_email) {}
	
void Parent::add_student(Student& student)
{
	_students.push_back(&student);
		
}

int Parent::students()
{
	//returns the size of vector parents
	return Parent::_students.size();
}

//Problem in this method
Student& Parent::student (int index)
{
	//returns parent at index
	if (index < 0 || index > Parent::_students.size())
		throw std::out_of_range("Invalid Index");
		
	return *Parent::_students[index];
}

std::string Parent::full_info() const
{    
	std::string s;
	
	for (auto& ptr: _students){
		
	   s += ptr->to_string() + ", ";
	}
	//returns everything in base class plus parent's student (students under parent)
	//return Parent.students;
	return Parent::name + " (" + Parent::email + " )" + ", Students: " + s;
}