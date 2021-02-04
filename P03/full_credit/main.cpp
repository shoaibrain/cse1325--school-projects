//#include "fraction.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Fraction{
	int x;
	
	public:
		Fraction(int x = 0):x{x}{}
		
		friend istream& operator >> (istream& input, Fraction& obj);
		friend ostream& operator << (ostream& output, Fraction& obj);
};

istream& operator >> (istream& input, Fraction& obj){
	input >> obj.x;
	return input;
}

ostream& operator << (ostream& output, Fraction& obj){
	output << obj.x<<endl;
	return output;
}

int main(){
	
	std::string user_input;
	//std:: cout << "Enter 2 fractions (n/d n/d): "
	//std::cin >> user_input
	
	Fraction f1;
	cin >> f1;
	cout << f1;
	
}