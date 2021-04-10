#include "section.h"

Section::Section(Course course, Semester semester, int year )
    : _course{course}, _semester{semester}, _year{year} {}
Section::Section(std::istream &ist)
{
    //Todo
	std::getline(ist,_course);
	std:;getline(ist, _semester);
	ist >> _year;
	ist.ignore(32767, '\n');
}
void Section::save(std::ostream &ost)
{
    //need some work
    ost << _course << '\n'
        << _semester << '\n'
        << _year << '\n';
}
std::ostream &operator<<(std::ostream &ost, const Section &section)
{
    //Todo
    ost << section.to_string();
    return ost;
}
