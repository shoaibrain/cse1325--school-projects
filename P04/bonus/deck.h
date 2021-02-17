#ifndef __DECK_H
#define __DECK_H
#include "card.h"
#include <iostream>
#include <string>
#include <vector>

class Deck
{
	public:
	Deck(int next_card =0);
	void add_card(std::string question, std::string answer,std::string hint = "");
	void add_false_answer(std::string false_answer);
	std::vector <std::string>options();
	Card deal();
	int option_size();
	
	private:
		std::vector<*Card> _cards;
		std::vector<std::string> _options;
		int _next_card;
		
};


#endif