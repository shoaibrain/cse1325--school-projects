#include "deck.h"
#include "card.cpp"
#include <iostream>
#include <string>
#include <vector>

//Create an empty vector for cards of type Card
vector <Card> _cards;

//Create an empty vector for cards of type Card
vector <std::string> _options;

//method add_card
void add_card(std::string question, std::string answer)
{
	//Create a card object with question and answer
	card = Card(question,answer);
	//add card into vector _cards
	_cards.push(card);
	
	
	//push answer parameter to vector _options
	_options.push(answer);
	

} 


//method add_false_answer
void add_false_answer(std::string false_answer)
{		//add false answers to the vector _options
		_options.push(false_answer);
}

