#ifndef __SEMESTER_H
#define __SEMESTER_H
#include <istream>
#include <ostream>
enum class Semester{
	FALL,
	SPRING,
	SUMMER
	

};

	std::ostream& operator<<(std::ostream& ost, const Semester& semester);
	Semester load_semester(std::istream &ist);
	std::string semester_to_string(Semester semester);
	Semester string_to_semester(std::string semester);
#endif