#include "student.h"
#include "parent.h"
#include <iostream>
#include <vector>
#include <string>

//std::vector<Person*> people;
std::vector<Student*> _student;
std::vector<Parent*> _parent;

void add_parent(){
	
	std::string name;
	std::string email;
	
	std::cout << "Enter parent's name: ";
	std::getline(std::cin, name);
	std::cin.ignore();
	
	std::cout << "Enter parent's email: ";
	std::getline(std::cin,email);
	std::cin.ignore();
	
	//Create parent object
	Parent p1{name, email};
	//Push parent object in person vector
	_parent.push_back(&p1);
	return;
};

void add_student(){
	
	std::string name;
	std::string email;
	int grade;
	//ask student name
	std::cout << "Enter student's name: ";
	std::getline(std::cin, name);
	std::cin.ignore();
	//ask student email
	std::cout << "Enter student's email: ";
	std::getline(std::cin,email);
	std::cin.ignore();
	//ask student grade
	std::cout << "Enter student's grade: ";
	std::cin >> grade;
	std::cin.ignore();
	
	//Create student object
	Student s1{name, email,grade};
	//Push parent object in person vector
	_student.push_back(&s1);
	return;
	
	
};

void pair(){
	
};

void list_student(){
	
	for(auto p : _student)
	{
       std::cout<< "full_info(): " << p->full_info() << "\n\n";
	}
	return;
	
};

void list_parent(){
	
	for(auto p : _parent)
	{
       std::cout<< "full_info(): " << p->full_info() << "\n\n";
	}
	return;
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
	std::cin.ignore();
	
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