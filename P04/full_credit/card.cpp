#include "card.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <string>
 
Card::Card(std::string question, std::string answer):
	_question{ question }, _answer{ answer }

std::string Card::attempt(std::string response)
{
	boost::to_upper(response);
	if (response == _answer)
	{
		return std::cout<< "Correct!";
	}
	else
	{
		return std::cout<<"X - Correct answer was "<< _answer;
	}
}
