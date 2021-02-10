#include "card.h"
#include <iostream>
#include <string> 
 
Card::Card(std::string question, std::string answer):
	_que{ numerator }, _d{ denominator } {reduce();}



std::ostream& operator<<(std::ostream &out, const Fraction &f1)
{
	out << f1._n << '/' << f1._d;
	return out;
}
std::istream& operator>>(std::istream &in, Fraction &f1)
{
	// Overwrite the values of f1
	in >> f1._n;
 
	// Ignore the '/' separator
	in.ignore(std::numeric_limits<std::streamsize>::max(), '/');
 
	in >> f1._d;
 
	// Since we overwrite the existing f1, we need to reduce again
	f1.reduce();
 
	return in;
}
void Fraction::print()
	{
		std::cout << _n << '/' << _d << '\n';
	}