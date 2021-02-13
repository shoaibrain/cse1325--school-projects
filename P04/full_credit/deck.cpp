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


Deck::Deck(Card cards, std::string options,int next_card,std::string question,std::string answer)
	:Card{ question, answer},  //call Card(question,answer) constructor
	 _cards{cards},_options{options}, _next_card{next_card} //Deck Class
	{}

//method add_card
void add_card(std::string question, std::string answer)
{
	//Create a card object with question and answer
	card = Card(question,answer);
	//add card into vector _cards
	Deck::_cards.push(card);
	
	
	//push answer parameter to vector _options
	Deck::_options.push(answer);
	

} 
//Sort in alphabetical order
bool mycomp(std::string a, std::string b){
	//returns 1 if string a is alphabetically 
	//less than string b
	//quite similar to strcmp operation
	return a < b;
}

//method add_false_answer
void add_false_answer(std::string false_answer)
{		//add false answers to the vector _options
		Deck::_options.push(false_answer);
}

//method options returns a copy of vector string _options
std::vector <std::string> _options(_options)
{
	//sort the _options vector
	std::sort(_options.begin(),_options.end(), mycomp);
	
	return _options;
	
}

