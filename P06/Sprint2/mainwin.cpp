
#include "mainwin.h"
#include <iostream> // for std::cerr logging

Mainwin::Mainwin() : nim{nullptr} {


    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(600, 300);
    set_title("The SMART System");

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);
	
	// /////// ////////////////////////////////////////////////////////////////
    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);
    // vbox->add(*menubar);
	
	// F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);
	
    //         N E W   SMART
    // Append New to the File menu
    Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_New School", true));
    menuitem_new->signal_activate().connect([this] {this->on_new_game_click();});
    filemenu->append(*menuitem_new);

    //         Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);

    //     INSERT
    // Create a insert menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_Insert", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);
	
	//New Student
    Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_New Student", true));
    menuitem_new->signal_activate().connect([this] {this->on_new_game_click();});
    filemenu->append(*menuitem_new);	
	
	
	//New Parent
    Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_New Parent", true));
    menuitem_new->signal_activate().connect([this] {this->on_new_game_click();});
    filemenu->append(*menuitem_new);


    //     Relate
    // MenuBar to relate student and parent
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_Relate", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);
	
	//STUDENT TO PARENT
	Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_Student to Parent", true));
    menuitem_new->signal_activate().connect([this] {this->on_new_game_click();});
    filemenu->append(*menuitem_new);

}