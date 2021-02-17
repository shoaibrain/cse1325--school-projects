#ifndef __HINTCARD_H
#define __HINTCARD_H

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
	std::string attempt(std::string respose);
	
	//OutStream card
	friend std::ostream& operator<<(std::ostream& ost, const Card& card);
	
};


#endif