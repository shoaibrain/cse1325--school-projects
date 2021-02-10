#ifndef __DECK_H
#define __DECK_H

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
	Card deal();
	
	private:
		std::vector<Card> _cards;
		std::vector<std:;string> _options;
		int _next_card;
		
};


#endif