// #include "student.h"
// #include "parent.h"

#include "mainwin.h"

int main(int argc, char *argv[])
{
    srand(time(NULL));
    auto app = Gtk::Application::create(argc, argv, "edu.uta.smart");
    Mainwin win;
    return app->run(win);
}
