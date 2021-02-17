#include "card.h"
#include <iostream>
#include <algorithm>
#include <string>
//Constructor for class card
Card::Card(std::string question, std::string answer):
	_question(question), _answer(answer) {}

//attemp method: returns string type
std::string Card::attempt(std::string response)
{	
	std::string correct_answer = this->_answer;
	//convert the input respose to uppercase
	transform(response.begin(),response.end(), response.begin(),::toupper);
	transform(correct_answer.begin(),correct_answer.end(),correct_answer.begin(),::toupper);
	
	
	if (correct_answer == response)
	{
		return "Correct!\n";
	}
	else
	{	return "X - Correct answer was " + _answer + "\n";

	}
}

std::ostream& operator<<(std::ostream& ost, const Card& card) {
    ost << card._question;
    
    return ost;
}