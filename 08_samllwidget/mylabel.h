#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class myLabel : public QLabel
{
    Q_OBJECT
public:
    explicit myLabel(QWidget *parent = nullptr);


public:
    void enterEvent(QEvent *event);     //鼠标进入
    void leaveEvent(QEvent *event);     //鼠标移出

    void mousePressEvent(QMouseEvent *ev);      //鼠标按下
    void mouseReleaseEvent(QMouseEvent *ev);    //鼠标松开

signals:

};

#endif // MYLABEL_H
