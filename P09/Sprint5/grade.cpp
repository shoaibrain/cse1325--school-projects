#include "grade.h"
#include <stdexcept>

std::ostream& operator<<(std::ostream& ost, const Grade& grade) {
    ost << grade_to_string.at(grade);
    return ost;
}
Grade load_grade(std::istream& ist) {
    std::string from_stream;
    std::getline(ist, from_stream);
    for(const auto& [grade, g] : grade_to_string)
        if(g == from_stream) return grade;
    throw std::runtime_error{std::string{"Invalid grade: " + from_stream}};
}

std::string string_grade(Grade grade){
	if (grade == Grade::A) return "A";
	else if (grade == Grade::B) return "B";
	else if (grade == Grade::C) return "C";
	else if (grade == Grade::D) return "D";
	else if (grade == Grade::F) return "F";
	else if (grade == Grade::I) return "Incomplete";
	else return "In Progress";
}