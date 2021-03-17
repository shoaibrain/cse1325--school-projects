
#include "mainwin.h"
#include <iostream> // for std::cerr logging

Mainwin::Mainwin() {


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





}