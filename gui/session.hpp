#pragma once
#include <QTabWidget>
#include <QWidget>

class Session : public QWidget {
 private:
  QTabWidget* _tabs;

 public:
  Session();
  ~Session();
};
