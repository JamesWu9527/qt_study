#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    //对定时器进行重写
    void timerEvent(QTimerEvent *evt);

    int m_Timer1;
    int m_Timer2;

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
