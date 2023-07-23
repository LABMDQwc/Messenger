#include "main_window.h"
#include <QTabWidget>

MainWindow::MainWindow(QMainWindow *parent)
    : QMainWindow(parent)
{
    QTabWidget *tab = new QTabWidget(this);
    tab->setGeometry(0,0,750,30);
    setWindowTitle("Messenger");
}
