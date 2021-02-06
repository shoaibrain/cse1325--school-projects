#include "fraction.h"
#include <limits>
#include <iostream>
 
 
Fraction::Fraction(int numerator, int denominator):
	_n{ numerator }, _d{ denominator } {reduce();}

int Fraction::gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

void Fraction::reduce()
{
	if (_n != 0 && _d != 0)
		{
			int gcd{ Fraction::gcd(_n, _d) };
			_n /= gcd;
			_d /= gcd;
		}
}

//Division
Fraction Fraction::operator/(const Fraction& f2)
{
	return Fraction(_n*f2._d, _d * f2._n );
}

//Addition
Fraction Fraction::operator+(const Fraction& f2)
{
	return Fraction{ _n * f2._d + _d*f2._n, _d * f2._d };
}
//Multiplication
Fraction Fraction::operator*(const Fraction& f2)
{
	return Fraction{ _n * f2._n, _d * f2._d };
}
//Negation
Fraction Fraction::operator-()const
{
	Fraction temp;
	temp._n = -_n;
	temp._d = _d;
	return temp;
}

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