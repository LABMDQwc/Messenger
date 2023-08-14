#pragma once
#include <QMainWindow>

class MainWindow : public QMainWindow {
public:
    MainWindow(QMainWindow *parent = nullptr);
    ~MainWindow();
    void start();
public slots:
    void slot();
};
