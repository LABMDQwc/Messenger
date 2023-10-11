#pragma once
#include <QTabWidget>
#include <QWidget>
#include <QVBoxLayout>

class Session : public QWidget {
 private:
  QVBoxLayout* _layout;
  QTabWidget* _tabs;
  QWidget* contacts;

 public:
  Session();
  ~Session();
};
