#include "mysubwidget.h"

MySubWidget::MySubWidget(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("Son Windows");
    this->resize(400,600);

    m_btn = new QPushButton("SonWindows",this);

    connect(m_btn,&QPushButton::clicked,this,&MySubWidget::ChangeSlots);

}

void MySubWidget::ChangeSlots()
{
    emit ChangeSignal();
}
