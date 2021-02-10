#ifndef __FRACTION_H
#define __FRACTION_H

#include "card.h"
#include "card.cpp"
#include <iostream>
#include <string>
 #include <vector>
class Deck
{
	public:
	add_card(std::string question, std::string answer);
	add_false_answer(std::string false_answer);
	std::vector <std::string>options();
	Card:: deal();
};


#endif