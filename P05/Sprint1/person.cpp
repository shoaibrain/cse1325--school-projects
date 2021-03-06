#include "person.h"
#include <iostream>
#include <string>

//constructor for class Person
Person::Person (std::string get_name,std::string get_email):
	name{ get_name }, email { get_email } {}
	
//to_string. return name of the person
std::string Person::to_string()
{
	
}
//return email in parentheses
std::string Person::full_info()
{
	
}


std::ostream& operator<<(std::sotream& ost, const Person& person)
{
	ost<<person.name;
	return ost;
}