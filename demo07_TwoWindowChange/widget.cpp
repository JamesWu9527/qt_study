#include "widget.h"
#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("Main Window");
    this->resize(400,600);
    QPushButton *btn01 = new QPushButton("MainWindow",this);

    connect(btn01,&QPushButton::clicked,this,&Widget::myslots);

    //绑定sub窗口点击按钮的事件,处理子窗口过来的信号
    connect(&sub,&MySubWidget::ChangeSignal,this,&Widget::ChangeWindow);
}

Widget::~Widget()
{
}

void Widget::myslots()
{
    //对当前窗口进行一个隐藏操作
    this->hide();
    sub.show();
}

void Widget::ChangeWindow()
{
    //对子窗口进行一个隐藏操作
    sub.hide();
    this->show();
}

