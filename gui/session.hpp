#pragma once
#include <QWidget>
#include <QTabWidget>

class Session : public QWidget {
private:
    QTabWidget *_tabs;
public:
    Session();
    ~Session();
};
