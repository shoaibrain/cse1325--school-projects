#ifndef __TRANSCRIPT_H
#define __TRANSCRIPT_H

#include "section.h"
#include "student.h"
#include "grade.h"

class Transcript{
	public:
		Transcript(Section& section, Student& student);
		void assign_grade(Grade grade);
		friend std::ostream& operator<<(std::ostream& ost, const Transcript& transcript);
		
	
	private:
		Section& _section;
		Student& _student;
		Grade _grade;
}




#endif
