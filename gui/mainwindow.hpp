#pragma once
#include <QMainWindow>
#include <QTcpSocket>

class MainWindow : public QMainWindow {
    Q_OBJECT
private:
    QTcpSocket *_socket;
    void makeconnection();
public:
    MainWindow();
    ~MainWindow();
};
