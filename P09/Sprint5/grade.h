#ifndef __GRADE_
#define __GRADE_

#include <iostream>
#include <vector>
#include <map>
#include <cctype>
#include <ostream>

enum class Grade {A, B, C, D, F, I, X};
const std::vector<Grade> grades_vector {
    Grade::A, Grade::B, Grade::C, Grade::D, 
    Grade::F, Grade::I, Grade::X,
};

std::string string_grade(Grade grade);

const std::map<Grade, std::string> grade_to_string {
  {Grade::A, "A"},
  {Grade::B, "B"},
  {Grade::C, "C"},
  {Grade::D, "D"},
  {Grade::F, "F"},
  {Grade::I, "In Progress"},
  {Grade::X, "Incomplete"},
};

std::ostream& operator<<(std::ostream& ost, const Grade& grade);
Grade load_grade(std::istream& ist);

#endif
