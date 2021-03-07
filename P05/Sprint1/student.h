#ifndef __STUDENT_H
#define 


#include <string>
#include <vector>

Parent Parent;

class Student: public Person {
	using Person::Person;
	public:
		Student(std::string name, std::string email,int grade);
		void add_parent(Parent& parent);
		int parents();
		Parent& parent(int index);
		std::string full_info() const override;
	protected:
		int grade;
		std::vector<Parent*> parents;

		
}

#endif