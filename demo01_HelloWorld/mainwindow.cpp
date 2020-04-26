#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("第一个QT程序"));    //改变窗口的标题
    qDebug()<<"在控制台进行调试信息的输出";

    //模态窗口
    QDialog dlg(this);
    dlg.setWindowTitle(tr("我是一个模态窗口"));
    dlg.resize(300,300);
    dlg.exec();

    //非模态窗口
    m_dlg2 = new QDialog();
    m_dlg2->setWindowTitle(tr("我是一个非模态的窗口"));
    m_dlg2->resize(300,300);
    m_dlg2->show();

}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_dlg2;
}

