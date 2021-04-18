#include "section.h"
#include "semester.h"
#include "teacher.h"

Section::Section(Course course, Semester semester, int year, Teacher teacher) 
  : _course{course}, _semester{semester}, _year{year}, _teacher{teacher} { }
  
Section::Section(std::istream& ist) : _course{ist}, _teacher{ist} {
    _semester = load_semester(ist);
    ist >> _year; ist.ignore(32767, '\n');
	//_teacher 
	
	
}
void Section::save(std::ostream& ost) {
    _course.save(ost);
    ost << _semester << '\n' << _year << '\n' << _teacher << '\n';
}
std::ostream& operator<<(std::ostream& ost, const Section& section) {
    ost << section._course << " for " << section._semester << ' ' << section._year << " with " << section._teacher;
    return ost;
}

