#include "semester.h"
#include <cctype>
#include <ostream>


std::string semester_to_string(Semester semester){
	if (semester == Semester::FALL)return "fall";
	else if (semester == Semester::SPRING) return "spring";
	else if (semester == Semester::SUMMER) return "summer";
	else return "invalid subject";
}



void load_semester(std::istream &ist){
	std::string _semester;
	
	std::getline(ist,_semester);
}

std::ostream& operator<<(std::ostream& ost, const Semester& semester){
	ost<<(semester);
	return ost;
	
};