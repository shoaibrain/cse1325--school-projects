#ifndef __CARD_H
#define __CARD_H

#include <iostream>
#include <string>
 
class Card
{
protected:
	std::string _question;
	std::string _answer;
 
public:
	Card(std::string question, std::string answer);
	//return type string
	virtual std::string attempt(std::string respose);
	
	//OutStream card
	friend std::ostream& operator<<(std::ostream& ost, const Card& card);
	
};


#endif