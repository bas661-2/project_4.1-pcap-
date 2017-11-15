#ifndef START_H
#define START_H
#include <QMainWindow>
#include <QDebug>
#include "mainwindow.h"
#include "traffic.h"


namespace Ui {
class Start;
}

class Start : public QMainWindow
{
    Q_OBJECT

public:
    explicit Start(QWidget *parent = 0);
    ~Start();

private slots:
    void MainWindowWindow();
    void TrafficWindow();

private:
    Ui::Start *ui;
};

#endif // START_H
