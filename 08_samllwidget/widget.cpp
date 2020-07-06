#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //绑定事件 使用自定义控件的get事件
    connect(ui->btn_get, &QPushButton::clicked, [=](){
        qDebug()<<"获取的值："<<ui->widget_slef->getNum();
    });

    //绑定事件 使用自定义控件的set事件
    connect(ui->btn_set, &QPushButton::clicked, [=](){
        ui->widget_slef->setNum(50);
    });



}

Widget::~Widget()
{
    delete ui;
}

