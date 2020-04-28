#include "mywidget.h"
#include "ui_mywidget.h"
#include <QHBoxLayout>      //水平布局
#include <QVBoxLayout>      //垂直布局
#include <QGridLayout>      //栅格布局

mywidget::mywidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mywidget)
{
    ui->setupUi(this);
    setWindowTitle(tr("布局管理"));

    //通过代码 对控件 进行一个布局的管理（垂直布局 和 水平布局）
//    QVBoxLayout *layout = new QVBoxLayout;
//    layout->addWidget(ui->fontComboBox);
//    layout->addWidget(ui->textEdit);
//    layout->setSpacing(10);     //设置部件间的间隔
//    layout->setContentsMargins(10,10,10,10); //左上右下
//    setLayout(layout);

    //栅格布局
//    QGridLayout *layout = new QGridLayout;
//    //添加部件 从0行0列开始 占 1行2列
//    layout->addWidget(ui->fontComboBox,0,0,1,2); //控件，开始的行，列，占位行，列
//    layout->addWidget(ui->pushButton,0,2,1,1);
//    layout->addWidget(ui->textEdit,1,0,1,3);
//    setLayout(layout);



}

mywidget::~mywidget()
{
    delete ui;
}

