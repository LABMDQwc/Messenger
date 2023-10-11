#include "session.hpp"

Session::Session() : _layout(new QVBoxLayout), _tabs(new QTabWidget), contacts(new QWidget) {
  setGeometry(1000, 1000, 1000, 1000);
  _tabs->addTab(contacts, "+");
  _tabs->addTab(contacts, "3");
  _tabs->addTab(contacts, "2");
  contacts->show();
  _layout->addWidget(_tabs);
}

Session::~Session() {
  delete _tabs;
}
