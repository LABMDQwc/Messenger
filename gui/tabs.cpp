#include "tabs.h"

Tabs::Tabs(QTabWidget *parent)
    : QTabWidget(parent)
{
    QTabWidget *tabs = new QTabWidget(this);
    tabs->setGeometry(0, 0, 750, 27);
    setWindowTitle("Messenger");
}
