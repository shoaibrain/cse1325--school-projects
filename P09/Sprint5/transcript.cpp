#include <iostream>
#include "transcript.h"


Transcript::Transcript(Section& section, Student& student)
	: _section{section},_student{student} {}


void Transcript::assign_grade(Grade grade){
		_grade = grade;
}


std::ostream& operator<<(std::ostream& ost, const Transcript& transcript) {
    ost << transcript._student << " is in " << transcript._section << " has grade " << transcript._grade;
    return ost;
}
