#ifndef __MAINWIN_H
#define __MAINWIN_H


#include <gtkmm.h>
#include "person.h"
#include "student.h"
#include "parent.h"

class Mainwin : public GTK::window{
	public:
		Mainwin();
		virtual ~Mainwin();
	
	protected:
		void on_new_school_click();
		void on_new_student_click();
		void on_new_parent_click();
		void on_student_parent_click();
		void on_quit_click();
		
	
	private:
		Gtk::Label *display;
		
};



#endif