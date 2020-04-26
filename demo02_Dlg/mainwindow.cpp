#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("信号和槽的基本使用"));

    //将按钮的点击事件和槽函数绑定起来
    //参数详解：发送者，事件，接收者，槽函数
    connect(ui->btn_Test,&QPushButton::clicked,this,&MainWindow::btn_TestFunc);

    //还可以在UI设计界面 进行信号和槽的绑定 那样更简单 F4进行编辑 F3退出编辑
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::btn_TestFunc()
{
    QDialog *dlg = new QDialog(this);
    dlg->setWindowTitle(tr("我是一个子窗口"));
    dlg->resize(300,300);
    dlg->show();
}

