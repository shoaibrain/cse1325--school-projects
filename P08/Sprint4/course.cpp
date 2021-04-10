#include "course.h"

Course::Course(Subject subject, int grade)
	: _subject{subject}, _grade{grade}{}
	
Course::Course(std::istream &ist){
	//Todo
	std::getline(ist,_subject);
	ist >> _grade;
	ist.ignore(32767, '\n');
	
}
void Course::save(std::ostream &ost){
	//Todo
	ost << _subject << '\n' << _grade << '\n';
}

std::ostream &operator<<(std::ostream &ost, const Course &course){
	ost << course.to_string();
	return ost;
}