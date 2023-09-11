#include "mainwindow.hpp"
#include "authorization.hpp"
#include "session.hpp"

MainWindow::MainWindow() : _socket(new QTcpSocket) {
  setGeometry(550, 250, 230, 200);
  makeconnection();
  Auth* auth = new Auth(_socket);
  setCentralWidget(auth);
  Session* session = new Session();
  setCentralWidget(session);
}

MainWindow::~MainWindow() {
  _socket->close();
  delete _socket;
}

void MainWindow::makeconnection() {
  _socket->connectToHost("localhost", 19518);
  if (_socket->waitForConnected(3000)) {
    qDebug() << "Connected!";
  }
}
