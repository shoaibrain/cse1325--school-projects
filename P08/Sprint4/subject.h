#ifndef __SUBJECT_H
#define __SUBJECT_H
#include <istream>
#include <ostream>
enum class Subject{

		READING,
		WRITING,
		MATH,
		SCIENCE,
		HISTORY,
		ART,
		MUSICSPORTS
		
	
};

std::ostream& operator<<(std::ostream& ost, const Subject& subject);
void load_semester(std::istream &ist);

std::string subject_to_string(Subject subject);

#endif