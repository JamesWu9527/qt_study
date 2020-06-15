#include "mywidget.h"
#include <QPushButton>
#include "myqpushbutton.h"
#include <QDebug>

/*
快捷键
注释 ctrl + /
运行 ctrl + r
编译 ctrl + b
帮助文档     F1
自动对齐     ctrl + i
同名之间的h文件和cpp文件切换    F4
*/

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    //创建一个按钮
    QPushButton *btn = new QPushButton;
    btn->setParent(this);
    //设置按钮的文本
    btn->setText("第一个按钮");

    //创建第二个按钮   按照控件的大小来设置窗口的大小
    QPushButton *btn2 = new QPushButton("第二个按钮",this);

    //重置窗口的大小
    //this->resize(600,400);
    btn2->move(100,100);

    //设置窗口标题
    this->setWindowTitle("我是标题");

    //设置固定窗口大小
    this->setFixedSize(600,400);

    //创建一个自己的按钮对象
    myQpushButton *btn3 = new myQpushButton;
    btn3->setText("自己设定的按钮");
    btn3->move(200,0);
    btn3->setParent(this);  //设置到对象中

}

myWidget::~myWidget()
{
    qDebug()<<"mywidget析构函数";
}

