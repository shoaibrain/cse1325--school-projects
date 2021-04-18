#include <iostream>
#include "transcript.h"


Transcript::Transcript(Student& student, Section& section)
	: _student{student}, _section{section} {}


void Transcript::assign_grade(Grade grade){
		_grade = grade;
}


std::ostream& operator<<(std::ostream& ost, const Transcript& transcript) {
    ost << transcript._student << " is in " << transcript._section << " has grade " << transcript._grade;
    return ost;
}
