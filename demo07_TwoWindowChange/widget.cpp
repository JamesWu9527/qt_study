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
    void(MySubWidget::*signal)() = &MySubWidget::ChangeSignal;
    connect(&sub,signal,this,&Widget::ChangeWindow);

    void(MySubWidget::*signal2)(int,QString) = &MySubWidget::ChangeSignal;
    //connect(&sub,signal2,this,&Widget::ChangeWindowDebug);

    //使用lamda表达式
    connect(&sub,signal2,this,[](int a,QString str){
        qDebug()<<a<<" "<<str.toUtf8().data();
    });

    //测试lamda表达式
    QPushButton *btn02 = new QPushButton("lamda",this);
    btn02->move(100,100);
    int a=20,b=30;
    connect(btn02,&QPushButton::clicked,[=](){
        qDebug()<<a<<b;
    });
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

void Widget::ChangeWindowDebug(int a, QString str)
{
    //对子窗口进行一个隐藏操作
    /*
    sub.hide();
    this->show();
    */
    qDebug()<<a<<" "<<str.toUtf8().data();
}

void Widget::ChangeWindow()
{
    //对子窗口进行一个隐藏操作
    sub.hide();
    this->show();
}

