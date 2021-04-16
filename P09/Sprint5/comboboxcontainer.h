#ifndef __COMBOBOXCONTAINER_H
#define __COMBOBOXCONTAINER_H

#include <gtkmm.h>
#include <stdexcept>
template <class T>
class ComboBoxContainer : public Gtk::MessageDialog {
  public:
    ComboBoxContainer();
};
#endif
