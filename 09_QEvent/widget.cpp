#include "widget.h"
#include "ui_widget.h"
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //启动定时器
    m_Timer1 = this->startTimer(1000); //单位是毫秒
    m_Timer2 = this->startTimer(2000); //单位是毫秒

    //定时器的第二种使用方法
    QTimer *timer = new QTimer(this);
    timer->start(500);
    connect(timer,&QTimer::timeout,[=](){
        static int num = 1;
        ui->label_3->setText(QString::number(num++));
    });

    //点击按钮 暂停定时器显示
    connect(ui->btn_stop, &QPushButton::clicked,[=](){
        timer->stop();
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *evt)
{
    if (evt->timerId() == m_Timer1)
    {
        static int num = 1;
        ui->label->setText(QString::number(num++));
    }

    if (evt->timerId() == m_Timer2)
    {
        static int num2 = 1;
        ui->label_2->setText(QString::number(num2++));
    }

}

