#include "deck.h"
#include "card.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//Create an empty vector for cards of type Card
//vector <Card> _cards;

//Create an empty vector for cards of type Card
//vector <std::string> _options;


Deck::Deck(int next_card)
	: _next_card{next_card} //Deck Class
	{}

//method add_card
void add_card(std::string question, std::string answer)
{
	//Create a card object with question and answer
	card = Card(question,answer);
	//add card into vector _cards
	_cards.push_back(card);
	
	
	//push answer parameter to vector _options
	_options.push_back(answer);
	

} 
//Sort in alphabetical order
//bool mycomp(std::string a, std::string b){
	//returns 1 if string a is alphabetically 
	//less than string b
	//quite similar to strcmp operation
	//return a < b;
//}

//method add_false_answer
void add_false_answer(std::string false_answer)
{		//add false answers to the vector _options
		_options.push_back(false_answer);
}

//method options returns a copy of vector string _options
std::vector <std::string> _options(_options)
{
	//sort the _options vector
	std::sort(_options.begin(),_options.end());
	
	return _options;
	
}

