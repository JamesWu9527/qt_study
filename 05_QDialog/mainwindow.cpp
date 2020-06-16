#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QColorDialog>
#include <QFileDialog>
#include <QFontDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //点击新建按钮弹出一个对话框
    connect(ui->actionnew, &QAction::triggered,[=](){
        //对话框 分为模态对话框 和 非模态对话框

        //创建一个模态对话框
        QDialog dlg(this);
        dlg.resize(300,300);
        dlg.setWindowTitle("我是一个模态对话框");
        dlg.exec();

        qDebug()<<"模态对话框成功销毁";

    });

    //创建一个非模态对话框
    connect(ui->actionopen, &QAction::triggered, [=](){
        QDialog *dlg2 = new QDialog(this);
        dlg2->setWindowTitle("我是一个非模态对话框");
        dlg2->resize(300,300);
        dlg2->show();
        dlg2->setAttribute(Qt::WA_DeleteOnClose);   //在关闭的时候进行内存释放

        qDebug()<<"非模态对话框弹出来了";
    });

    connect(ui->actionmessage, &QAction::triggered, [=](){
        //测试消息对话框
        QMessageBox::critical(this,"critical","错误");
        QMessageBox::information(this,"Info","信息");
        QMessageBox::question(this,"ques","提问", QMessageBox::Save | QMessageBox::Ok);
    });

    connect(ui->actioncolor, &QAction::triggered, [=](){
        //颜色对话框
        QColor color = QColorDialog::getColor(QColor(255,0,0));
        qDebug()<<"r = "<<color.red() <<"g = "<<color.green()<<" b = "<<color.blue();
    });

    //文件对话框
    connect(ui->actionFile, &QAction::triggered, [=](){
        //文件对话框的操作
        QString strFileName = QFileDialog::getOpenFileName(this,"打开文件","F:\\Code-Project\\QT\\qt_study.git\\trunk","*.cpp");
        qDebug()<<"打开的文件是:"<<strFileName;
    });

    //字体对话框
    connect(ui->actionfont, &QAction::triggered, [=](){
        //字体对话框
        bool bflag;
        QFont font = QFontDialog::getFont(&bflag, QFont("华文彩云",36));
        qDebug()<<"字体:"<<font.family().toUtf8().data()<<"字号:"<<font.pointSize()<<"是否加粗:"<<font.bold()<<"是否倾斜:"<<font.italic();

    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

