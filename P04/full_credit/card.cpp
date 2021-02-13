#include "card.h"
#include "deck.h"
#include <iostream>
#include <algorithm>
#include <string>
//Constructor for class card
Card::Card(std::string question, std::string answer):
	_question( question ), _answer( answer ) {}

//attemp method: returns string type
std::string Card::attempt(std::string response)
{	//convert the input respose to uppercase
	transform(response.begin(),response.end(),response.begin(),::toupper);
	if (response == _answer)
	{
		return "Correct!\n";
	}
	else
	{	return "X - Correct answer was " + _answer + "\n";

	}
}
