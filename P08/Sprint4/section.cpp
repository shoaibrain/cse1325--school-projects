#include "section.h"
#include "course.h"
#include "semester.h"
#include "subject.h"
#include <iostream>

Section::Section(Course course, Semester semester, int year )
    : _course{course}, _semester{semester}, _year{year} {}


Section::Section(std::istream& ist){    
	_course(ist);
	
	load_semester(ist);
	
	ist >> _year;
	ist.ignore(32767, '\n');
	
}

void Section::save(std::ostream &ost)
{
	 _course.save(ost);
	 ost << _semester << "\n" << _year << "\n";
	 
}
std::ostream &operator<<(std::ostream &ost, const Section &section)
{
    //Todo
    ost << section;
    return ost;
}
