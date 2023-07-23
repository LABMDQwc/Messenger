#include "main_window.h"
#include <QApplication>

int main(int Argc, char *Argv[])
{
    QApplication app(Argc, Argv);
    MainWindow main_window;
    main_window.resize(750,500);
    main_window.show();
    return app.exec();
}
