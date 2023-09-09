#include "session.hpp"

Session::Session() : _tabs(new QTabWidget) {
    setGeometry(550, 250, 1000, 1000);
}

Session::~Session() {
    delete _tabs;
}
