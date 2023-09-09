#include "authorization.hpp"
#include <QLabel>

Auth::Auth(QTcpSocket *socket) : _login(new QLineEdit), _pass(new QLineEdit), _btn_login(new QPushButton("Log in")), _btn_sign(new QPushButton("Sign up")), _layout(new QVBoxLayout), _socket(socket) {
    connect(_btn_login, SIGNAL(clicked()), this, SLOT(login()));
    connect(_btn_sign, SIGNAL(clicked()), this, SLOT(signup()));
    _pass->setEchoMode(QLineEdit::Password);
    _layout->addWidget(_login);
    _layout->addWidget(_pass);
    _layout->addWidget(_btn_login);
    _layout->addWidget(_btn_sign);
    setLayout(_layout);
}

Auth::~Auth() {
    delete _login;
    delete _pass;
    delete _btn_login;
    delete _btn_sign;
    delete _layout;
}

QString Auth::get_login() {
    return _login->text();
}

QString Auth::get_pass() {
    return _pass->text();
}

void Auth::login() {
    QLabel *log_in = new QLabel("Haven't logged in");
    _socket->write("LOGIN\n");
    _socket->write(get_login().toLocal8Bit());
    _socket->write("\n");
    _socket->write(get_pass().toLocal8Bit());
    _socket->write("\nEND");
    _socket->waitForBytesWritten(1000);
    _socket->waitForReadyRead(3000);
    if (!qstrcmp(_socket->readLine().data(), "LOGIN")) {
        log_in->setText("Log in Successfully");
        qDebug() << "log in";
    } else {
        log_in->setText("Failed logging in");
        qDebug() << "fail log in";
    }
    _layout->addWidget(log_in);
    delete log_in;
}

void Auth::signup() {
    QLabel *sign_up = new QLabel("Haven't registered");
    _socket->write("SIGNUP\n");
    _socket->write(get_login().toLocal8Bit());
    _socket->write("\n");
    _socket->write(get_pass().toLocal8Bit());
    _socket->write("\nEND");
    _socket->waitForBytesWritten(1000);
    _socket->waitForReadyRead(3000);
    if (!qstrcmp(_socket->readLine().data(), "REGISTER")) {
        sign_up->setText("Registered Successfully");
         qDebug() << "registered";
    }
    _layout->addWidget(sign_up);
    delete sign_up;
}
