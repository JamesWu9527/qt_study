#include "mywidget.h"
#include "ui_mywidget.h"
#include <QFrame>
#include <QFont>
#include <QMovie>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    //设置frame的状态
    ui->frame_test->setFrameStyle(QFrame::Box|QFrame::Sunken);
    ui->frame_test->setLineWidth(5);
    ui->frame_test->setMidLineWidth(10);

    QFont font;
    font.setFamily(tr("楷体"));   //字体类型
    font.setPointSize(20);  //字号
    font.setBold(true);     //加粗
    font.setItalic(true);   //斜体
    ui->label_test->setFont(font);
    ui->label_test->setText(tr("我是一个label"));
    ui->label_test->setFixedSize(200,50);

    //如果label显示内容过长 可以使用elidedText()函数进行设置

    //使用pixmap设置
    ui->label_png->setFixedSize(400,400);
    //ui->label_png->setPixmap(QPixmap(":/png/test.png"));  //显示图片

    QMovie *gif = new QMovie(":/png/111.gif");
    ui->label_png->setMovie(gif);
    gif->start();

}

MyWidget::~MyWidget()
{
    delete ui;
}

