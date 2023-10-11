#include "mainwindow.hpp"
#include "authorization.hpp"
#include "session.hpp"

MainWindow::MainWindow() : _socket(new QTcpSocket) {
  setGeometry(550, 250, 230, 200);
  make_connection();
  Auth* auth = new Auth(_socket);
  setCentralWidget(auth);
  connect(auth, SIGNAL(textlogin()), this, SLOT(make_session()));
}

MainWindow::~MainWindow() {
  _socket->close();
  delete _socket;
}

void MainWindow::make_connection() {
  _socket->connectToHost("localhost", 19518);
  if (_socket->waitForConnected(300)) {
    qDebug() << "Connected!";
  };
}

void MainWindow::make_session() {
  _session = new Session();
  setCentralWidget(_session);
}
