#include "mainwindow.hpp"
#include "authorization.hpp"
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>

MainWindow::MainWindow(QMainWindow *parent) : QMainWindow(parent) {
    setWindowTitle("Messenger");
    setGeometry(500, 150, 300, 300);
}

MainWindow::~MainWindow() {
}

void MainWindow::start() {
    Auth *auth = new Auth(this);
    this->setCentralWidget(auth);

    this->show();
}
