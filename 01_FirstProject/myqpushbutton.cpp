#include "myqpushbutton.h"
#include <QDebug>

myQpushButton::myQpushButton(QWidget *parent) : QPushButton(parent)
{
    qDebug()<<"我的构造函数";
}

myQpushButton::~myQpushButton()
{
    qDebug()<<"我的析构函数";

}
