#include <fraction.h>
#include <iostream>
#include <limits>
 
 
Fraction::Fraction(int numerator =0, int denominator =1):
	_n{ numerator }, _d{ denominator } {reduce()}

static int Fraction::gcd(int a, int b)
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

Fraction::Fraction operator/(const Fraction &f1, const Fraction &f2)
{
	return { f1._n*f2._d, f1._d * f2._n };
}
Fraction::Fraction operator+(const Fraction &f1, const Fraction &f2)
{
	return { f1._n * f2._d + f1._d*f2._n, f1._d * f2._d };
}
Fraction::Fraction operator*(const Fraction &f1, const Fraction &f2)
{
	return { f1._n * f2._n, f1._d * f2._d };
}
Fraction::Fraction operator*(const Fraction &f1, int value)
{
	return { f1._n * value, f1._d };
}
Fraction::Fraction operator*(int value, const Fraction &f1)
{
	return { f1._n * value, f1._d };
}
Fraction::std::ostream& operator<<(std::ostream &out, const Fraction &f1)
{
	out << f1._n << '/' << f1._d;
	return out;
}
Fraction::std::istream& operator>>(std::istream &in, Fraction &f1)
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
Fraction::void print()
	{
		std::cout << _n << '/' << _d << '\n';
	}