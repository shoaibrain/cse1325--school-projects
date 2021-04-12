#include "semester.h"
#include <cctype>
#include <ostream>


std::string semester_to_string(Semester semester){
	if (semester == Semester::FALL)return "fall";
	else if (semester == Semester::SPRING) return "spring";
	else if (semester == Semester::SUMMER) return "summer";
	else return "invalid subject";
}



Semester load_semester(std::istream &ist){
	std::string semester;
	std::getline(ist,semester);
	return string_to_semester(semester);
}
Semester string_to_semester(std::string semester){

	if (semester == "fall") return Semester::FALL;
	else if (semester == "spring") return Semester::SPRING;
	else if (semester == "summer") return Semester::SUMMER;
}

std::ostream& operator<<(std::ostream& ost, const Semester& semester){
	ost<<(semester);
	return ost;
	
}