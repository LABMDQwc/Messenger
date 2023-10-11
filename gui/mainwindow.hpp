#pragma once
#include "session.hpp"
#include <QMainWindow>
#include <QTcpSocket>

class MainWindow : public QMainWindow {
  Q_OBJECT
 private:
  Session* _session;
  QTcpSocket* _socket;
  void make_connection();

 public:
  MainWindow();
  ~MainWindow();
 private slots:
  void make_session();
};
