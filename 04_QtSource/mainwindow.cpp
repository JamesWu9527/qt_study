#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ui->actionnew->setIcon(QIcon("F:/Code-Project/QT/qt_study.git/trunk/04_QtSource/hello.jpg"));

    //使用QT的资源文件
    ui->actionnew->setIcon(QIcon(":/hello.jpg"));       //格式冒号 + 前缀名 + 文件名
    ui->actionopen->setIcon(QIcon(":/01.jpg"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

