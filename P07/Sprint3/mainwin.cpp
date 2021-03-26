#include <string>
#include "mainwin.h"
#include "entrydialog.h"
#include <iostream> // for std::cerr logging
#include <fstream>


const std::string APP = "Smart School";
const std::string VERSION = "0.2";
const std::string DEFAULTFN = "untitled.smart";

		
Mainwin::Mainwin() :filename{DEFAULTFN}{

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(650, 450);
    set_title("The SMART System");

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);
	
	
    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);
    
	
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

	
    //       SAVE
    // Append SAVE to the File menu
    Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save", true));
    menuitem_save->signal_activate().connect([this] {this->on_save_click();});
    filemenu->append(*menuitem_save);
	
	
    //       SAVE AS
    // Append SAVE AS to the File menu
    Gtk::MenuItem *menuitem_save_as = Gtk::manage(new Gtk::MenuItem("_Save As", true));
    menuitem_save_as->signal_activate().connect([this] {this->on_save_as_click();});
    filemenu->append(*menuitem_save_as);

    //       OPEN
    // Append SAVE AS to the File menu
    Gtk::MenuItem *menuitem_open = Gtk::manage(new Gtk::MenuItem("_Open", true));
    menuitem_open->signal_activate().connect([this] {this->on_open_click();});
    filemenu->append(*menuitem_open);

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
	
    //     H E L P
    // Create a Help menu and add to the menu bar
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);

    //           A B O U T
    // Append About to the Help menu
    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("_About", true));
    menuitem_about->signal_activate().connect([this] {this->on_about_click();});
    helpmenu->append(*menuitem_about);
	
	//////////////////////////////////////////////////
	////////  TOOLBAR  //////////////////////////////
   
   // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->pack_start(*toolbar, Gtk::PACK_SHRINK, 0);
	
	//     N E W   S C H O O L
    // Add a new school icon
    Gtk::ToolButton *new_school_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    new_school_button->set_tooltip_markup("Create a new school, discarding any in progress");
    new_school_button->signal_clicked().connect([this] {this->on_new_school_click();});
    toolbar->append(*new_school_button);

    //     O P E N   S 	C H O O L
    // Add an open school icon
    Gtk::ToolButton *open_school_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::OPEN));
    open_school_button->set_tooltip_markup("Open a school from disk file, discarding any in progress");
    open_school_button->signal_clicked().connect([this] {this->on_open_click();});
    toolbar->append(*open_school_button);

    //     S A V E   S C H O O L
    // Add a save school icon
    Gtk::ToolButton *save_school_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::SAVE));
    save_school_button->set_tooltip_markup("Save this school to disk file");
    save_school_button->signal_clicked().connect([this] {this->on_save_click();});
    toolbar->append(*save_school_button);
	
	
    //   S A V E  A S  S C H O O L
    // Add a save as school icon
    Gtk::ToolButton *save_as_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::SAVE_AS));
    save_as_button->set_tooltip_markup("Save this school to new disk file");
    save_as_button->signal_clicked().connect([this] {this->on_save_as_click();});
    toolbar->append(*save_as_button);

    Gtk::SeparatorToolItem *sep1 = Gtk::manage(new Gtk::SeparatorToolItem());
    toolbar->append(*sep1);

    //     C R E A T E   N E W  S T U D E N T 
    // Add a New student button to the toolbar
    Gtk::Image* student_image = Gtk::manage(new Gtk::Image{"student.png"});
    Gtk::ToolButton* new_student_button = Gtk::manage(new Gtk::ToolButton(*student_image));
    new_student_button->set_tooltip_markup("Create New Student");
    new_student_button->signal_clicked().connect([this] {this->on_new_student_click();});
    toolbar->append(*new_student_button);
	

    //     C R E A T E   N E W  PARENT
    // Add a New student button to the toolbar
    Gtk::Image* parent_image = Gtk::manage(new Gtk::Image{"family.png"});
    Gtk::ToolButton* new_parent_button = Gtk::manage(new Gtk::ToolButton(*parent_image));
    new_parent_button->set_tooltip_markup("Create New Parent");
    new_parent_button->signal_clicked().connect([this] {this->on_new_parent_click();});
    toolbar->append(*new_parent_button);
	
	//     RELATE STUDENT AND PARENT
    // Add relate student parent button to the toolbar
    Gtk::Image* relate_image = Gtk::manage(new Gtk::Image{"computer.png"});
    Gtk::ToolButton* relate_button = Gtk::manage(new Gtk::ToolButton(*relate_image));
    relate_button->set_tooltip_markup("Relate student & parent");
    relate_button->signal_clicked().connect([this] {this->on_student_parent_click();});
    toolbar->append(*relate_button);
	

	
	
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

void Mainwin::on_save_click() { 
 
  try {
	//Open an output file stream
        std::ofstream ofs{filename};
	//Write a size of student vector to ostream as a seperate line
		ofs << students.size() << '\n';
	//for each loop, call student's save method so it can write its own data to stream
	    for (int i = 0; i < students.size(); ++i){
			students[i].save(ofs);
		}
	//Write a size of parent vector to ostream as a seperate line
	    ofs << parents.size() << '\n';
	 //for each loop, call parent's save method so it can write its own data to stream
	    for (int i = 0; i < parents.size(); ++i){
			parents[i].save(ofs);
		}
	//close the file
	ofs.close();
        
		if(!ofs) throw std::runtime_error{"Error writing file " + filename};
    } 
	catch(std::exception& e) {
        Gtk::MessageDialog{*this, "Unable to save store: " + std::string{e.what()},
            false, Gtk::MESSAGE_WARNING}.run();
    }
 
 
}

void Mainwin::on_save_as_click() {
    Gtk::FileChooserDialog dialog("Please choose a file",
          Gtk::FileChooserAction::FILE_CHOOSER_ACTION_SAVE);
    dialog.set_transient_for(*this);

    auto filter_smart = Gtk::FileFilter::create();
    filter_smart->set_name("SMART files");
    filter_smart->add_pattern("*.smart");
    dialog.add_filter(filter_smart);
 
    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    dialog.set_filename("untitled.smart");

    //Add response buttons the the dialog:
    dialog.add_button("_Cancel", 0);
    dialog.add_button("_Save", 1);

    int result = dialog.run();

    if (result == 1) {
        filename = dialog.get_filename();
        on_save_click();  // Delegate to save
    }
}

//
// The user wants to open a store from the filesystem
//
void Mainwin::on_open_click() {
    Gtk::FileChooserDialog dialog("Please choose a file",
          Gtk::FileChooserAction::FILE_CHOOSER_ACTION_OPEN);
    dialog.set_transient_for(*this);

    auto filter_smart = Gtk::FileFilter::create();
    filter_smart->set_name("SMART files");
    filter_smart->add_pattern("*.smart");
    dialog.add_filter(filter_smart);
 
    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    dialog.set_filename("untitled.smart");

    //Add response buttons the the dialog:
    dialog.add_button("_Cancel", 0);
    dialog.add_button("_Open", 1);

    int result = dialog.run();
//students.push_back(Student{name,email,grade});
    if (result == 1) {
        try {
            filename = dialog.get_filename();
            std::ifstream ifs{filename};
			//clear the current school information
            on_new_school_click();
			
			//read the size of students vector from istream as a seperate line
            int student_size;
			//read line as string & change to integer
			ifs >> student_size;
			ifs.ignore(32767,'n');
			for (int i = 0; i < student_size; ++i){
				
				students.push_back(Student{ifs});
			}
			//Read the size of parent vector
			int parent_size;
			//read line as string & change it to string
			ifs >> parent_size;
			ifs.ignore(32767,'n');
			for (int i = 0; i < parent_size; ++i){
				parents.push_back( Parent{ifs});
			}
			
			//show_data();
			
			
			
        } catch (std::exception& e) {
            Gtk::MessageDialog{*this, "Unable to open smart: " + std::string{e.what()},
                false, Gtk::MESSAGE_WARNING}.run();
            //on_new_store_click(true);
        }
    }
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


////////////////////MISC////////////////////////

void Mainwin::on_about_click() {
    Gtk::AboutDialog dialog;
    dialog.set_transient_for(*this); // Avoid the discouraging warning
    dialog.set_program_name("SMART");
    auto logo = Gdk::Pixbuf::create_from_file("school.png");
    dialog.set_logo(logo);
    dialog.set_version("Version " + VERSION);
    dialog.set_copyright("Copyright 2021");
    dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
    std::vector< Glib::ustring > authors = {"Shoaib Rain, George F. Rice"};
    dialog.set_authors(authors);
    std::vector< Glib::ustring > artists = {
        "Students logo by flaticon (Free for commercial use, No attribution required)\nhttps://www.flaticon.com/search?word=family",
        "Family logo (Free for commercial use, No attribution required)\nhttps://www.flaticon.com/search?word=family",
        "Computer logo by https://www.flaticon.com/search?word=family",
        };
    dialog.set_artists(artists);
    dialog.run();
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
