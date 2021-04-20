#ifndef __COMBOBOXCONTAINER_H
#define __COMBOBOXCONTAINER_H

#include <gtkmm.h>
#include <stdexcept>
#include <sstream>

template <class T>
class ComboBoxContainer : public Gtk::ComboBoxText {
  public:
    ComboBoxContainer(const T& container){
		//iterate over the vector provided as a parameter
		for (auto& it:container){
			//change the current object into string
			 stringstream sso;
			 sso << it;
			 std::string current;
			 sso >> current;
			//Append the current string into ComboBoxText widget
			ComboBoxContainer.append(sso);
			
			
		}
		
	};
	//vector <c*> any_classes;
};
#endif
