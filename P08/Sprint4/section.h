#ifndef __SECTION_H
#define __SECTION_H

#include <iostream>
#include "semester.h"
#include "subject.h"
#include "course.h"
class Section
{
public:
    Section(Course course, Semester semester, int year);
    Section(std::istream& ist);
    void save(std::ostream &ost);
    friend std::ostream &operator<<(std::ostream &ost, const Section &section);

private:
    Course _course;
    Semester _semester;
    int _year;
	int _max_students;
};

#endif
