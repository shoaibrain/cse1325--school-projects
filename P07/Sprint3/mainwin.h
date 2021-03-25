#ifndef __MAINWIN_H
#define __MAINWIN_H


#include <gtkmm.h>
#include "person.h"
#include "student.h"
#include "parent.h"

class Mainwin : public Gtk::Window{
	public:
		Mainwin();
		virtual ~Mainwin();
	
	protected:
		void on_new_school_click();
		void on_new_student_click();
		void on_new_parent_click();
		void on_student_parent_click();
		void on_save_click();
		void on_save_as_click();
		void on_open_click();
		void on_quit_click();
		void on_about_click();
		
	
	private:
		
		Gtk::Label *display;
		std::string filename;
		void show_data();
		std::vector<Student> students;
		std::vector<Parent> parents;
		
		//Helper methods to get inputs from the user
		int get_int(std::string prompt);
        double get_double(std::string prompt);
        std::string get_string(std::string prompt);
		
};



#endif