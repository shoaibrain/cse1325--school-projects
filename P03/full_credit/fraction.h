#ifndef __FRACTION_H
#define __FRACTION_H

#include <vector>
#include <string>


class Fraction{
	public:
		Fraction (int numerator = 0, int denominator = 1){
			
		}
		int value();
		Fraction operator-();
		Fraction operator+(Fraction& rhs);
		Fraction operator-(Fraction& rhs);
		Fraction operator*(Fraction& rhs);
		Fraction operator/(Fraction& rhs);
		
	private:
		int _n;
		int _d;
		reduce();
};


#endif