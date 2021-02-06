#ifndef __FRACTION_H
#define __FRACTION_H

#include <vector>
#include <string>

#include <iostream>
#include <limits>
 
class Fraction
{
private:
	int _n;
	int _d;
 
public:
	Fraction(int numerator=0, int denominator=1);
	static int gcd(int a, int b);
	void reduce();
	
	//Multiplication Operator overloading
	Fraction operator*(const Fraction &f2);
	//Division operator overloading
	Fraction operator/(const Fraction &f2);
	//Addition operator overloading
	Fraction operator+(const Fraction &f2);
	//Division operator overloading
	Fraction operator-(const Fraction &f2);
	
	
	//Negate
	//friend Fraction operator-()const;
	
	//OutStream operator overloading
	friend std::ostream& operator<<(std::ostream &out, const Fraction &f1);
	//Instream operator overloading
	friend std::istream& operator>>(std::istream &in, Fraction &f1);
 
	void print();
};


#endif