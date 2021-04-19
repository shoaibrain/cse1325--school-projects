#ifndef __TRANSCRIPT_
#define __TRANSCRIPT_

#include "section.h"
#include "student.h"
#include "grade.h"

class Transcript{
	public:
		Transcript(Section& section, Student& student);
		void assign_grade(Grade grade);
		Transcript(std::istream& ist);
		friend std::ostream& operator<<(std::ostream& ost, const Transcript& transcript);
		
	
	private:
		Section& _section;
		Student& _student;
		Grade _grade;
};

#endif
