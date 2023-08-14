#pragma once
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

class Auth : public QWidget {
private:
    QLineEdit *fld_login;
    QLineEdit *fld_pass;
    QPushButton *btn_login;
    QPushButton *btn_reg;
public:
    Auth(QWidget *parent = nullptr);
    ~Auth();
    void auth();
signals:
    void signal();
};
