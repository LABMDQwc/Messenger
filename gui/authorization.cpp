#include "authorization.hpp"

Auth::Auth(QTcpSocket* socket)
    : _login(new QLineEdit),
      _pass(new QLineEdit),
      _btn_login(new QPushButton("Log in")),
      _btn_sign(new QPushButton("Sign up")),
      _info_label(new QLabel),
      _layout(new QVBoxLayout),
      _socket(socket) {
  connect(_btn_login, SIGNAL(clicked()), this, SLOT(login()));
  connect(_btn_sign, SIGNAL(clicked()), this, SLOT(signup()));
  _pass->setEchoMode(QLineEdit::Password);
  _layout->addWidget(_login);
  _layout->addWidget(_pass);
  _layout->addWidget(_btn_login);
  _layout->addWidget(_btn_sign);
  _layout->addWidget(_info_label);
  _info_label->setVisible(false);
  setLayout(_layout);
}

Auth::~Auth() {
  delete _login;
  delete _pass;
  delete _btn_login;
  delete _btn_sign;
  delete _layout;
  delete _info_label;
}

QString Auth::get_login() {
  return _login->text();
}

QString Auth::get_pass() {
  return _pass->text();
}

void Auth::login() {
  _info_label->setVisible(true);
  _socket->write("LOGIN\n");
  _socket->write(get_login().toLocal8Bit());
  _socket->write("\n");
  _socket->write(get_pass().toLocal8Bit());
  _socket->write("\nEND");
  _socket->waitForBytesWritten(250);
  _socket->waitForReadyRead(250);
  if (!qstrcmp(_socket->readLine().data(), "LOGIN")) {
    _info_label->setText("Logged in Successfully");
    emit textlogin();
  }
  else
    _info_label->setText("Failed logging in");
}

void Auth::signup() {
  _info_label->setVisible(true);
  _socket->write("SIGNUP\n");
  _socket->write(get_login().toLocal8Bit());
  _socket->write("\n");
  _socket->write(get_pass().toLocal8Bit());
  _socket->write("\nEND");
  _socket->waitForBytesWritten(250);
  _socket->waitForReadyRead(250);
  if (!qstrcmp(_socket->readLine().data(), "SIGNUP"))
    _info_label->setText("Registered Successfully");
}
