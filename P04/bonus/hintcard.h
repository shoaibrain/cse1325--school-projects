#ifndef __HINTCARD_H
#define __HINTCARD_H

#include <iostream>
#include <string>

#include "card.h"
 
class Hintcard: public Card
{
protected:
	std::string _hint;
 
public:
	//constructor
	Hintcard(std::string question, std::string answer,std::string hint);
	//return type string
	std::string attempt(std::string respose) override;
	
};


#endif