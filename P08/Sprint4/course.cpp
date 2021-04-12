#include "course.h"
#include <iostream>
Course::Course(Subject subject, int grade)
	: _subject{subject}, _grade{grade}{}
	
Course::Course(std::istream& ist){
	
	
}
void Course::save(std::ostream &ost){
	//Todo
	ost << _subject << '\n' << _grade << '\n';
}

std::ostream &operator<<(std::ostream &ost, const Course &course){
	ost << course;
	return ost;
}