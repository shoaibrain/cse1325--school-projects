#include "deck.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//Create an empty vector for cards of type Card
//vector <Card> _cards;

//Create an empty vector for cards of type Card
//vector <std::string> _options;


Deck::Deck(int next_card)
	: _next_card(next_card) //Deck Class
	{}

//method add_card
void Deck::add_card(std::string question, std::string answer)
{    
	//Create a card object with question and answer
	//add card into vector _cards
	_cards.push_back(Card(question,answer));
	
	
	//push answer parameter to vector _options
	_options.push_back(answer);
	

} 


//method add_false_answer
void Deck::add_false_answer(std::string false_answer)
{		//add false answers to the vector _options
		_options.push_back(false_answer);
}

//method options returns a copy of vector string _options
std::vector <std::string> Deck::options()
{
	//sort the _options vector
	std::sort(_options.begin(),_options.end());
	
	return _options;
	
}

