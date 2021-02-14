#include "deck.h"
#include "card.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <cstdlib>

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

Card Deck::deal()
{
	
	//All cards have been dealt. Shuffle the card and reset _next_card = 0		
	if (_next_card >= _cards.size())
	{
		
		std::random_shuffle ( _cards.begin(), _cards.end() );
		_next_card = 0;
	
	}
	
	//otherwise return reference to the card at that number
	Card obj = _cards[_next_card];
	//increment card
	_next_card +=1;
	
	return obj;
}

//method options returns a copy of vector string _options
std::vector <std::string> Deck::options()
{
	//sort the _options vector
	std::sort(_options.begin(),_options.end());
	
	return _options;
	
}

