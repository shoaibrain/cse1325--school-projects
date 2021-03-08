#include "student.h"
#include "parent.h"
#include <string>

//Constructor
Student::Student(std::string get_name, std::string get_email,int get_grade)
	:Person(get_name,get_email), grade(get_grade) {}
	
void Student::add_parent(Parent& parent)
{
	_parents.push_back(&parent);  //How to actually append address pointers? 
	
}

int Student::parents()
{
	//returns the size of vector parents
	return Student::_parents.size();
}

Parent& Student::parent (int index)
{
	//returns parent at index
	if (index < 0 || index > Student::_parents.size())
		throw std::out_of_range("Invalid Index");
		
	return *_parents.at(index);
}

std::string Student::full_info() const
{   std::string p;
    
	//for (auto& it: _parents){
		
	//    p.append(", " + it->to_string());
	//}
	
	auto begin{&_parents[0]};
	auto end{ begin + std::size(_parents) };
	for (auto ptr{ begin }; ptr != end; ++ptr){
		p.append(", " + ptr->to_string());
	}
	
	//returns everything in base class plus student's grade and parent's name
	//return Student.grade + Student.parent;
	return Student::name + " (" + Student::email + " )" + "Grade: " +std::to_string(Student::grade) + " Parents: " + p;
}