#include "start.h"
#include "ui_start.h"
#include "mainwindow.h"
#include "traffic.h"
#include "ui_mainwindow.h"
#include <QMainWindow>
MainWindow *myMainWindow;
Traffic *myTraffic;

Start::Start(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Start)
{
    ui->setupUi(this);
    myMainWindow = new MainWindow();
    myTraffic = new Traffic();
    connect(ui->calculator,SIGNAL(clicked()),this,SLOT(MainWindowWindow()));
    //connect(ui->action_calculator,SIGNAL(triggered()),this,SLOT(MainWindowWindow()));
    connect(ui->traffic,SIGNAL(clicked()),this,SLOT(TrafficWindow()));
    //connect(ui->action_traffic,SIGNAL(triggered()),this,SLOT(TrafficWindow()));
}


Start::~Start()
{
    delete myMainWindow;
    delete myTraffic;
    delete ui;
}

void Start::MainWindowWindow()
{
    myMainWindow->show();
}

void Start::TrafficWindow()
{
    myTraffic->show();
}
