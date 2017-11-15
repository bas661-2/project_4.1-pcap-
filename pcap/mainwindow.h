#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void digit_pressed();

    void on_pb_zapitay_clicked();
    void pb_pm_slot();
    void on_pb_c_clicked();
    void on_pb_rovno_clicked();
    void pb_bin_oper();

private:
    Ui::MainWindow *ui;

};


#endif // MAINWINDOW_H
