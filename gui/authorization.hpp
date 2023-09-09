#pragma once
#include <QWidget>
#include <QTcpSocket>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

class Auth : public QWidget {
    Q_OBJECT
private:
    QLineEdit *_login;
    QLineEdit *_pass;
    QPushButton *_btn_login;
    QPushButton *_btn_sign;
    QVBoxLayout *_layout;
    QTcpSocket *_socket;
public:
    Auth() = delete;
    Auth(QTcpSocket*);
    ~Auth();
    QString get_login();
    QString get_pass();
private slots:
    void login();
    void signup();
};
