#include "authorization.hpp"
#include <QVBoxLayout>

Auth::Auth(QWidget *parent) : QWidget(parent), fld_login(new QLineEdit), fld_pass(new QLineEdit),
    btn_login(new QPushButton("Log in")), btn_reg(new QPushButton("Sign up")) {
    auth();
}

Auth::~Auth() {
    delete fld_login;
    delete fld_pass;
    delete btn_login;
    delete btn_reg;
}

void Auth::auth() {
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(fld_login);
    layout->addWidget(fld_pass);
    layout->addWidget(btn_login);
    layout->addWidget(btn_reg);
    this->setLayout(layout);

}
