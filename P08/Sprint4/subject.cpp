#include <cctype>
#include "subject.h"
#include <ostream>


std::string subject_to_string(Subject subject){
	if (subject == Subject::READING)return "reading";
	else if (subject == Subject::WRITING) return "writing";
	else if (subject == Subject::MATH) return "math";
	else if (subject == Subject::SCIENCE) return "science";
	else if (subject == Subject::HISTORY) return "history";
	else if (subject == Subject::ART) return "art";
	else if (subject == Subject::MUSICSPORTS) return "musicsport";
	else return "invalid subject";
}

Subject string_to_subject(std::string subject){
	if (subject == "reading") return Subject::READING;
	else if (subject == "writing") return Subject::WRITING;
	else if (subject == "math") return Subject::MATH;
	else if (subject == "science") return Subject::SCIENCE;
	else if (subject == "history") return Subject::HISTORY;
	else if (subject == "art") return Subject::ART;
	else if (subject == "musicsport") return Subject::MUSICSPORTS;
	
}

Subject load_subject(std::istream &ist){
	std::string subject;
	std::getline(ist,subject);
	return string_to_subject(subject);
}


std::ostream& operator<<(std::ostream &ost, const Subject &subject){
	ost << subject_to_string(subject);
	return ost;
}