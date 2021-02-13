
#include "card.h"
#include "deck.h"
#include <iostream>
#include <string>

int main() {
	
	std::string question1 = "Reuse and extension of fields and method implementations from another class";
	std::string answer1 = "Inheritance ";
	
	std::string question2 = "Bundling data and code into a restricted container";
	std::string answer2 = "Encapsulation ";
	
	std::string question3 = "A special class member that creates and initializes an object from the class";
	std::string answer3 = "Constructor ";
	
	std::string question4 = "Providing a user-defined meaning to a pre-defined operator";
	std::string answer4 = "Operator Overloading";
	
	std::string question5 = "A derived class replacing its base class’ implementation of a method";
	std::string answer5 = "Override ";
	
	std::string question6 = "A data type that can typically be handled directly by the underlying hardware";
	std::string answer6 = "Primitive type";
	
	std::string question7 = "A data type consisting of a fixed set of constant values";
	std::string answer7 = "Enumerated type ";
	
	std::string question8 = "A class or a function (NOT a method!) that is granted access to its friend class’ privatemembers";
	std::string answer8 = "Friend";
	
	std::string question9 = " statement that introduces a name with an associated type into a scope";
	std::string answer9 = "Declaration ";
	
	std::string question10 = "A procedure for solving a specific problem, expressed in terms of an ordered set of actionsto execute";
	std::string answer10 = "Algorithm";
	
	std::string question11 = "An object created to represent an error or other unusual occurrence and then propagatedvia special mechanisms until caught by special handling code";
	std::string answer11 = "Exception ";
	
    //create question answer card
	card1 = Card(question,answer);
	card2 = Card(question,answer);
	card3 = Card(question,answer);
	card4 = Card(question,answer);
	card5 = Card(question,answer);
	card6 = Card(question,answer);
	card7 = Card(question,answer);
	card8 = Card(question,answer);
	card9 = Card(question,answer);
	card10 = Card(question,answer);
	
	
	
}