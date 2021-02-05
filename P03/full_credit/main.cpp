#include "fraction.h"
#include <iostream>

int main()
{
	Fraction f1;
	Fraction f2;
	std::cout << "Enter 2 fractions (n/d n/d): ";
	std::cin >> f1>>f2;
 
	
	std::cout << f1 << " / " << f2 << " = " << f1 / f2 << '\n';
	std::cout << f1 << " + " << f2 << " = " << f1 + f2 << '\n';
	//std::cout << f1 << " - " << f2 << " = " << f1 - f2 << '\n';
	std::cout << f1 << " * " << f2 << " = " << f1 * f2 << '\n';
 
	return 0;
}