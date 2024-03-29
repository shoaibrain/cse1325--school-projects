#ifndef __STUDENT_H
#define __STUDENT_H

#include "person.h"
#include "parent.h"
#include <vector>
#include <map>
#include <iterator>

class Parent;

class Student : public Person {
  public:
    Student(std::string name, std::string email, int grade);
    Student(std::istream& ist);
    void save(std::ostream& ost) override;
    void save_aggregates(std::ostream& ost);
    void load_aggregates(std::istream& ist, const std::map<std::string, Parent*>& parents);
    void add_parent(Parent& parent);
    //int parents();
    //Parent& parent(int index);
    std::string full_info() const override;
	typedef std::vector<Parent*>::iterator iterator;
    typedef std::vector<Parent*>::const_iterator const_iterator;
    iterator begin() {return _parents.begin();}
    iterator end() {return _parents.end();}
  protected:  
    int _grade;
    std::vector<Parent*> _parents;
};
	
#endif
