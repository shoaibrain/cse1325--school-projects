#include <iostream>
#include "fraction.h"

int main()
{
	Fraction f1;
	Fraction f2;
	std::cout << "Enter 2 fractions (n/d n/d): ";
	std::cin >> f1>>f2;
 
	//std::cout << "Enter fraction 2: ";
	//std::cin >> f2;
	//std::cout <<"Negative " << f1 <<" = " << -f1 << "\n";
	//std::cout <<"Negative " << f2 <<" = " << -f2 << "\n";
	std::cout << f1 << " + " << f2 << " = " << f1 + f2 << '\n';
	std::cout << f1 << " - " << f2 << " = " << f1 - f2 << '\n';
	std::cout << f1 << " * " << f2 << " = " << f1 * f2 << '\n';
	std::cout << f1 << " / " << f2 << " = " << f1 / f2 << '\n';
 
	return 0;
}