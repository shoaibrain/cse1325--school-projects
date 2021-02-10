#ifndef __FRACTION_H
#define __FRACTION_H

#include <iostream>
#include <string>
 
class Card
{
private:
	std::string _question;
	std::string _answer;
 
public:
	Card(std::string question, std::string answer);
	//return type string
	string attempt(std::string respose);
	
	//OutStream operator overloading
	friend std::ostream& operator<<(std::ostream &out, const Card &m);
	
};


#endif