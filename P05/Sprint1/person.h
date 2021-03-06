#ifndef __PERSON_H
#define __PERSON_H

#include <ostream>
#include <string>

class Person
{	
public:
	//Class constructor
	Person(std::string name,std::string email);
	std::string to_string();
	virtual std::string full_info();
	//OutStream person
	friend std::ostream& operator<<(std::ostream& ost, const Person& person);
protected:
	std::string name;
	std::string email;

};
#endif