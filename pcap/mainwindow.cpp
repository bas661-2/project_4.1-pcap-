#include "mainwindow.h"
#include "ui_mainwindow.h"

double firstNum;
bool UITSN = false;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pb_0,SIGNAL(clicked()),this,SLOT(digit_pressed()));
    connect(ui->pb_1,SIGNAL(clicked()),this,SLOT(digit_pressed()));
    connect(ui->pb_2,SIGNAL(clicked()),this,SLOT(digit_pressed()));
    connect(ui->pb_3,SIGNAL(clicked()),this,SLOT(digit_pressed()));
    connect(ui->pb_4,SIGNAL(clicked()),this,SLOT(digit_pressed()));
    connect(ui->pb_5,SIGNAL(clicked()),this,SLOT(digit_pressed()));
    connect(ui->pb_6,SIGNAL(clicked()),this,SLOT(digit_pressed()));
    connect(ui->pb_7,SIGNAL(clicked()),this,SLOT(digit_pressed()));
    connect(ui->pb_8,SIGNAL(clicked()),this,SLOT(digit_pressed()));
    connect(ui->pb_9,SIGNAL(clicked()),this,SLOT(digit_pressed()));

    connect(ui->pb_pm,SIGNAL(clicked()),this,SLOT(pb_pm_slot()));

    connect(ui->pb_plus,SIGNAL(clicked()),this,SLOT(pb_bin_oper()));
    connect(ui->pb_minus,SIGNAL(clicked()),this,SLOT(pb_bin_oper()));
    connect(ui->pb_umnozh,SIGNAL(clicked()),this,SLOT(pb_bin_oper()));
    connect(ui->pb_delit,SIGNAL(clicked()),this,SLOT(pb_bin_oper()));

    ui->pb_plus->setCheckable(true);
    ui->pb_minus->setCheckable(true);
    ui->pb_umnozh->setCheckable(true);
    ui->pb_delit->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::digit_pressed()
{
  QPushButton * button = (QPushButton*)sender();

  double lineEditNumber;
  QString newLineEdit;

  if ((ui->pb_plus->isChecked() || ui->pb_minus->isChecked()
       || ui->pb_umnozh->isChecked()
       || ui->pb_delit->isChecked()) && (!UITSN))
  {
      lineEditNumber = button->text().toDouble();
      UITSN = true;
      newLineEdit = QString::number(lineEditNumber,'g',15);
  }
  else
  {
      if (ui->lineEdit->text().contains('.') && button->text() == "0")
      {
          newLineEdit = ui->lineEdit->text()+button->text();
      }
      else
      {
      lineEditNumber = (ui->lineEdit->text() + button->text()).toDouble();
      newLineEdit = QString::number(lineEditNumber, 'g',15);
      }
  }
  ui->lineEdit->setText(newLineEdit);
}

void MainWindow::on_pb_zapitay_clicked()
{
        ui->lineEdit->setText(ui->lineEdit->text()+ ".");

}

void MainWindow::pb_pm_slot()
{
    QPushButton * button = (QPushButton*) sender();
    double lineEditNumber;
    QString newLineEdit;

    if(button->text() == "+/-")
    {
        lineEditNumber = ui->lineEdit->text().toDouble();
        lineEditNumber = lineEditNumber * -1;
        newLineEdit = QString::number(lineEditNumber,'g',15);
        ui->lineEdit->setText(newLineEdit);
    }
}

void MainWindow::on_pb_c_clicked()
{
    ui->pb_plus->setChecked(false);
    ui->pb_minus->setChecked(false);
    ui->pb_umnozh->setChecked(false);
    ui->pb_delit->setChecked(false);

    UITSN = false;

    ui->lineEdit->setText("0");
}

void MainWindow::on_pb_rovno_clicked()
{
          double lineEditNumber, secondNum;
          QString newLineEdit;

          secondNum = ui->lineEdit->text().toDouble();


          if (ui->pb_plus->isChecked())
          {
              lineEditNumber = firstNum + secondNum;
              newLineEdit = QString::number(lineEditNumber,'g',15);
              ui->lineEdit->setText(newLineEdit);
              ui->pb_plus->setChecked(false);
          }
          else if (ui->pb_minus->isChecked())
  {
      lineEditNumber = firstNum - secondNum;
      newLineEdit = QString::number(lineEditNumber,'g',15);
      ui->lineEdit->setText(newLineEdit);
      ui->pb_minus->setChecked(false);
  }
          else if (ui->pb_umnozh->isChecked())
  {
      lineEditNumber = firstNum * secondNum;
      newLineEdit = QString::number(lineEditNumber,'g',15);
      ui->lineEdit->setText(newLineEdit);
      ui->pb_umnozh->setChecked(false);
  }
          else if (ui->pb_delit->isChecked())
  {
      lineEditNumber = firstNum / secondNum;
      newLineEdit = QString::number(lineEditNumber,'g',15);
      ui->lineEdit->setText(newLineEdit);
      ui->pb_delit->setChecked(false);
  }

          UITSN = false;
  }
          void MainWindow::pb_bin_oper()
          {
              QPushButton * button = (QPushButton*) sender();

              firstNum = ui->lineEdit->text().toDouble();

              button->setChecked(true);
          }




