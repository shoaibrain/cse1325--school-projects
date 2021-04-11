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

void load_subject(std::istream &ist){
	std::string _subject;
	
	std::getline(ist,_subject);
}


std::ostream& operator<<(std::ostream &ost, const Subject &subject){
	ost << subject_to_string(subject);
	return ost;
};