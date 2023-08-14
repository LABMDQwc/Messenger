#include "mainwindow.hpp"
#include <QApplication>
#include <QtNetwork/QTcpSocket>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    MainWindow w;
    QTcpSocket *socket = new QTcpSocket;
    socket->connectToHost("localhost", 19518);
//    if (socket->state() == QTcpSocket::ConnectedState) {
        w.start();
//    }
    return app.exec();
}
