#include "main_window.h"
#include "tabs.h"
#include <QTabWidget>

MainWindow::MainWindow(QMainWindow *parent)
    : QMainWindow(parent)
{
    Tabs *tabs = new Tabs();
    tabs->show();

    setWindowTitle("Messenger");
}
