#include "course.h"
#include "subject.h"
#include <iostream>
Course::Course(Subject subject, int grade)
	: _subject{subject}, _grade{grade}{}
	
Course::Course(std::istream& ist){
	std::string subject;
	std::getline(ist,subject);
	ist >> _grade;
	ist.ignore(32767, '\n');

	_subject = string_to_subject(subject);
}
void Course::save(std::ostream &ost){
	//Todo
	ost << subject_to_string(_subject) << '\n' << _grade << '\n';
}

std::ostream &operator<<(std::ostream &ost, const Course &course){
	ost << course;
	return ost;
}