#include "smallwidget.h"
#include "ui_smallwidget.h"
#include <QSpinBox>
#include <QSlider>
#include <QDebug>

SmallWidget::SmallWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SmallWidget)
{
    ui->setupUi(this);

    ui->spinBox->setRange(1,100);
    ui->horizontalSlider->setRange(1,100);

    //设置Spinbox和进度条联动
    void(QSpinBox:: *spSignal)(int) = &QSpinBox::valueChanged;
    connect(ui->spinBox, spSignal, ui->horizontalSlider, &QSlider::setValue);

    //设置进度条和Spinbox进行联动
    connect(ui->horizontalSlider,&QSlider::valueChanged, ui->spinBox, &QSpinBox::setValue);

}

SmallWidget::~SmallWidget()
{
    delete ui;
}

void SmallWidget::setNum(int num)
{
    ui->spinBox->setValue(num);
}

int SmallWidget::getNum()
{
    return ui->spinBox->value();
}
