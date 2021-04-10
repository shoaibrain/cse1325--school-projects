#ifndef __COURSE_H
#define __COURSE_H
#include  <iostream>

class Course{
	public:
		Course(Subject subject, int grade);
		Course(std::istream &ist);
		void save(std::ostream &ost);
		friend std::ostream &operator<<(std::ostream &ost, const Course &course);
		
	private:
		Subject _subject;
		int _grade;
		
			
};

#endif
