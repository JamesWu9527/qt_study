#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "mysubwidget.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    void myslots();
    void ChangeWindow();    //处理子窗口过来的信号

private:
    MySubWidget sub;
};
#endif // WIDGET_H
