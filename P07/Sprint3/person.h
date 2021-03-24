#ifndef __PERSON_H
#define __PERSON_H

#include <iostream>
#include <fstream>

class Person {
  public:
    Person(std::string name, std::string email);
	Person(std::istream& ist); //Open previously saved person
	virtual void save(std::ostream& ost); //Save the person
    std::string to_string() const;
    virtual std::string full_info() const;
    friend std::ostream& operator<<(std::ostream& ost, const Person& person);
  protected:
    std::string _name;
    std::string _email;
};

#endif
