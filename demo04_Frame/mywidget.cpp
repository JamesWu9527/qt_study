#include "mywidget.h"
#include "ui_mywidget.h"
#include <QFrame>
#include <QFont>
#include <QMovie>
#include <QLCDNumber>
#include <QDebug>
#include <QMenu>
#include <QCompleter>
#include <QDateTime>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("基本控件的使用"));

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
    ui->label_test->setFixedSize(200,30);

    //如果label显示内容过长 可以使用elidedText()函数进行设置

    //使用pixmap设置
    ui->label_png->setFixedSize(200,200);
    //ui->label_png->setPixmap(QPixmap(":/png/test.png"));  //显示图片

    //播放gif图片
    QMovie *gif = new QMovie(":/png/111.gif");
    ui->label_png->setMovie(gif);
    gif->start();

    //LCDnumber部件
    ui->lcdNumber->setSmallDecimalPoint(true);  //设置显示小数点
    ui->lcdNumber->setDigitCount(6);    //设置显示6个数字
    ui->lcdNumber->setMode(QLCDNumber::Dec);    //十进制显示
    ui->lcdNumber->setFixedSize(200,50);
    ui->lcdNumber->display(123456);

    //pushbutton 相关
    ui->pushBtn1->setText(tr("&nihao"));    //设置加速键 Alt + n 触发
    ui->pushBtn2->setText(tr("帮助(&H)"));
    //ui->pushBtn2->setIcon(QIcon());   //设置图标
    ui->pushBtn3->setText(tr("z&oom"));

    QMenu *menu = new QMenu(this);
    menu->addAction(tr("放大"));
    ui->pushBtn3->setMenu(menu);

    //LineEdit 的一些常用
    ui->lineEdit1->setEchoMode(QLineEdit::Password);
    ui->lineEdit2->setInputMask(tr(">AA-90-bb-! aa#H;*"));
    connect(ui->lineEdit1, &QLineEdit::returnPressed, this,&MyWidget::lineEdit2_returnPressed);

    //设置自动补全
    QStringList wordList;
    wordList<<tr("你好")<<tr("你是谁")<<tr("你是JamesWu9527");
    QCompleter *complete = new QCompleter(wordList,this);   //新建自动完成器
    complete->setCaseSensitivity(Qt::CaseInsensitive);  //不区分大小写
    ui->lineEdit4->setCompleter(complete);

    //时间控件
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());

    //滑块控件
    ui->spinBox->setRange(0,100);
    ui->doubleSpinBox->setRange(0.01,1.00);

    //这里我们使用的是带参数的信号和槽 用SIGNAL 和 SLOT 来将对应的函数包裹起来
    //这里就不需要和上面一样 使用类名::信号          类名::槽函数     这个需要注意，如果加了 将不会生效
    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(spinBoxChangeValue(int)));


}

MyWidget::~MyWidget()
{
    delete ui;
}


void MyWidget::on_pushBtn1_toggled(bool checked)
{
    qDebug()<<tr("按钮是否按下：")<<checked;
}

void MyWidget::lineEdit2_returnPressed()
{
    //qDebug()<<tr("line1 获取了 Enter 键入");
    ui->lineEdit3->setFocus();  //line3获取到焦点

}

void MyWidget::spinBoxChangeValue(int value)
{
    //qDebug()<<tr("触发了此函数")<<value;
    ui->horizontalSlider->setValue(value);
    ui->verticalSlider->setValue(value);
}
