#include "student.h"
#include "parent.h"
#include <iostream>
#include <vector>
#include <string>

std::vector<Person*> people;

void add_parent(){
	std::string name;
	std::string email;
	
	std::cout << "Enter parent's name: ";
	std::cin >> name;
	
	std::cout << "Enter parent's email: ";
	std::cin >> email;
	//Create parent object
	Parent p1_1{name, email};
	//Push parent object in person vector
	people.push_back(&p1_1);
	
};

void add_student(){
	
};

void pair(){
	
};

void list_student(){
	
};

void list_parent(){
	
};

void run(){
	int option;
	
	std::cout << "Create and add new parent  (press 1)"<<std::endl;
	std::cout << "Create and add new Student (press 2)"<<std::endl;
	std::cout << "Pair existing student with existing parent (press 3)"<<std::endl;
	std::cout << "List full info for every student in vector (press 4)"<<std::endl;
	std::cout << "List full info for every parent in vector (press 5)"<<std::endl;
	
	std::cout << "\nEnter the number corresponding to your choice: ";
	std::cin >> option;
	
	if (option == 1)
		add_parent();
	else if (option == 2)
		add_student();
	else if (option == 3)
		pair();
	else if (option == 4)
		list_student();
	else if (option == 5)
		list_parent();
	else{
		std::cout << "Invalid Input" << std::endl;
	}
	

}

int main(){
	int flag = 1;
	
	do
	{
		std::cout << "Welcome to the program"<<std::endl;
		run();
		
		std::cout<<"Enter 1 to continue or 0 to quit: ";
		std::cin>>flag;
		
	}while (flag != 0);
	
	
	return 0;
	
}