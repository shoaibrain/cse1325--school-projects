#include <string>
#include "mainwin.h"
#include "entrydialog.h"
#include <iostream> // for std::cerr logging
		
		
Mainwin::Mainwin() {

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(500, 300);
    set_title("The SMART System");

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);
	
	
    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);
    //vbox->add(*menubar);
	
    //     F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    //         N E W   School
    // Append New to the File menu
    Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_New School", true));
    menuitem_new->signal_activate().connect([this] {this->on_new_school_click();});
    filemenu->append(*menuitem_new);

    //         Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);

	//     INSERT
    // Create a insert menu and add to the menu bar
    Gtk::MenuItem *menuitem_insert = Gtk::manage(new Gtk::MenuItem("_Insert", true));
    menubar->append(*menuitem_insert);
    Gtk::Menu *insertmenu = Gtk::manage(new Gtk::Menu());
    menuitem_insert->set_submenu(*insertmenu);
	
	//           NEW STUDENT
    // Append New Student to the INSERT menu
    Gtk::MenuItem *menuitem_new_student = Gtk::manage(new Gtk::MenuItem("_New Student", true));
    menuitem_new_student->signal_activate().connect([this] {this->on_new_student_click();});
    insertmenu->append(*menuitem_new_student);
	
	
	
	//           NEW PARENT
    // Append New parent to the INSERT menu
    Gtk::MenuItem *menuitem_new_parent = Gtk::manage(new Gtk::MenuItem("_New Parent", true));
    menuitem_new_parent->signal_activate().connect([this] {this->on_new_parent_click();});
    insertmenu->append(*menuitem_new_parent);

	//     RELATE
    // Create a relate menu and add to the menu bar
    Gtk::MenuItem *menuitem_relate = Gtk::manage(new Gtk::MenuItem("_Relate", true));
    menubar->append(*menuitem_relate);
    Gtk::Menu *relatemenu = Gtk::manage(new Gtk::Menu());
    menuitem_relate->set_submenu(*relatemenu);
	
	
	//   Student to parent
    // Append student to parent to the INSERT menu
    Gtk::MenuItem *menuitem_student_to_parent = Gtk::manage(new Gtk::MenuItem("_Student to Parent", true));
    menuitem_student_to_parent->signal_activate().connect([this] {this->on_student_parent_click();});
    relatemenu->append(*menuitem_student_to_parent);
	
	//Main window display
	display = Gtk::manage(new Gtk::Label());
	display->set_hexpand(true);
	display->set_vexpand(true);
	vbox->add(*display);
	
	display->set_text("Students\n\nParents");
	
	

	vbox-> show_all();
	

}
Mainwin::~Mainwin(){}

//CALL BACKS

void Mainwin::on_new_school_click(){
	//Clears the vector and updates the display
	students.clear();
	parents.clear();
	
	//Show updated display
	show_data();
	
	
	
}

void Mainwin::on_new_student_click(){
	//do something
	try{
	std::string name = get_string("Student name?");
	std::string email = get_string("Student email?");
	int grade = get_int("Student grade?");
	//Instance student class and add it to the student vector
	students.push_back(Student{name,email,grade});
	
	show_data();
	} catch (std::exception& e){}
	
}

void Mainwin::on_new_parent_click(){
	//do something
	try{
	std::string name = get_string("Parent name?");
	std::string email = get_string("Parent email?");
	//Instance parent class and add it to the parent vector
	parents.push_back(Parent({name,email}));
	
	show_data();
	}catch (std::exception& e){}
}

void Mainwin::on_student_parent_click(){
	    //Option to select students
		try{
		std::string prompt_student = "Select Student\n";
		int i;
		for (i = 0; i < students.size();i++){
			std::ostringstream oss;
			oss <<i <<") "<< students[i] << "\n";
			prompt_student += oss.str();
		}
		//get selction student int from the given options	
		int student = get_int(prompt_student);
		
		//Option to select Parent
		std::string prompt_parent = "Select Parent\n";
		int j;
		for (j = 0; j < parents.size();j++){
			std::ostringstream oss;
			oss <<j <<") "<< parents[j] << "\n";
			prompt_parent += oss.str();
		}
		//get selection parent int from the given options
		int parent = get_int(prompt_parent);
		
		try {
                students.at(student).add_parent(parents.at(parent));
                parents.at(parent).add_student(students.at(student));
            } 
		catch(...) {
                std::cerr << "Invalid selection!" << std::endl;
            }
		
		show_data();
		} catch (std::exception& e){}
}

void Mainwin::show_data(){
	std::string s = "Students\n\n";
		int i;
		int j;
		for (i = 0; i < students.size();++i){
		std::ostringstream oss;
		oss << students[i].full_info() << "\n";
		s += oss.str();
		}
	
        s += "\nParents\n\n";	    
		
		for (j = 0; j < parents.size();++j){
		std::ostringstream oss;
		oss << parents[j].full_info() << "\n";
		s += oss.str();
		}
		//Display all the data in the dataset
		display-> set_text(s);
	

}



void Mainwin::on_quit_click(){
	//Close the window
	close();
}

std::string Mainwin::get_string(std::string prompt) {
    EntryDialog edialog(*this, "<big>            </big>", true);
    edialog.set_secondary_text(prompt, true);
    if(edialog.run() == Gtk::RESPONSE_CANCEL) throw std::runtime_error{"CANCEL"};
    return edialog.get_text();
}

double Mainwin::get_double(std::string prompt) {
    while(true) {
        try {
            return std::stod(get_string(prompt));
        } catch (std::invalid_argument& e) {
            prompt = "Invalid value, please try again:";
        }
    }
}

int Mainwin::get_int(std::string prompt) {
    while(true) {
        try {
            return std::stoi(get_string(prompt));
        } catch (std::invalid_argument& e) {
            prompt = "Invalid value, please try again:";
        }
    }
}