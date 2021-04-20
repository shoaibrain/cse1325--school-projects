#include <iostream>
#include "transcript.h"


Transcript::Transcript(Section& section, Student& student)
	: _section{section},_student{student} {}

//Transcript(std::istream& ist):_section(ist),_student(ist),_grade(ist){}

void Transcript::assign_grade(Grade grade){
		_grade = grade;
}


void Transcript::save(std::ostream& ost) {
    
    ost << _section << '\n' << _student << '\n' << _grade << '\n';
}


std::ostream& operator<<(std::ostream& ost, const Transcript& transcript) {
    ost << "In "<< transcript._section<<": "  << transcript._student << " earned a " << transcript._grade;
    return ost;
}
