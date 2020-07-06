#include "mylabel.h"
#include <QDebug>
#include <QMouseEvent>

myLabel::myLabel(QWidget *parent) : QLabel(parent)
{

}

void myLabel::enterEvent(QEvent *event)
{
    qDebug()<<"鼠标进入";
}

void myLabel::leaveEvent(QEvent *event)
{
    qDebug()<<"鼠标离开";
}

void myLabel::mousePressEvent(QMouseEvent *ev)
{
    //鼠标左键按下
    if (ev->button() == Qt::LeftButton)
    {
        QString str = QString("鼠标按下的位置: x = %1 y = %2").arg(ev->x()).arg(ev->y());
        qDebug()<<str;
    }
}

void myLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    //鼠标左键松开
    if (ev->button() == Qt::LeftButton)
    {
        QString str = QString("鼠标松开的位置: x = %1 y = %2").arg(ev->x()).arg(ev->y());
        qDebug()<<str;
    }
}
