#ifndef __DECK_H
#define __DECK_H
#include "card.cpp"
#include <iostream>
#include <string>
#include <vector>

class Deck : public Card
{
	public:
	Deck(Card cards, std::string options,int next_card,std::string question,std::string answer);
	void add_card(std::string question, std::string answer);
	void add_false_answer(std::string false_answer);
	std::vector <std::string>options();
	Card deal();
	
	private:
		std::vector<Card> _cards;
		std::vector<std::string> _options;
		int _next_card;
		
};


#endif