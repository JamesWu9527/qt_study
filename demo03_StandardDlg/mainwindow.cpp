#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QColorDialog>
#include <QFileDialog>
#include <QFontDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QProgressDialog>
#include <QErrorMessage>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("常用的窗口类型"));
    m_err = new QErrorMessage(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_ColorDlg_clicked()
{
    QColor color = QColorDialog::getColor(Qt::red,this,tr("选择窗口的背景色"));
    if (color.isValid())
    {
        QString str = "background-color:";
        str += color.name();
        this->setStyleSheet(str);   //设置客户区的背景色
        qDebug()<<"当前的color argb值:"<<color;
    }

}

void MainWindow::on_btn_FileDlg_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("文件对话框"));
    qDebug()<<"选择的文件路径："<<fileName;
}

void MainWindow::on_btn_FontDlg_clicked()
{
    bool bFlag = false;
    QFont font = QFontDialog::getFont(&bFlag,this);
    if (bFlag)
    {
        this->setFont(font);    //将客户区的字体改变
        qDebug()<<tr("字体类型：")<<font;
    }

}

void MainWindow::on_btn_InputDlg_clicked()
{
    bool bFlag = false;
    QString strResult = QInputDialog::getText(this,tr("提取字符串"),tr("输入你的名字"),QLineEdit::Normal,tr("JamesWu9527"),&bFlag);
    if (bFlag)
    {
        qDebug()<<tr("输入的内容是：").toUtf8().data()<<strResult.toUtf8().data(); //这里是去掉引号然后输出
    }
}

void MainWindow::on_btn_MessageDlg_clicked()
{
    int ret = QMessageBox::question(this,tr("我是标题"),tr("你好吗？"),QMessageBox::Yes);
    if (QMessageBox::Yes == ret)
    {
        qDebug()<<tr("你很好？");
    }
}

void MainWindow::on_btn_ProgressDlg_clicked()
{
    QProgressDialog dlg(tr("文件复制进度"),tr("取消"),0,100,this);
    dlg.setWindowTitle(tr("我是进度条对话框"));
    //dlg.setModal(true);
    dlg.setWindowModality(Qt::WindowModal); //设置为模态对话框
    dlg.show();

    for (int i=0; i<=100; i++)
    {
        dlg.setValue(i);
        _sleep(100);        //不建议使用这个，这里演示 用一下
        if (dlg.wasCanceled())
        {
            break;
        }
    }
}

void MainWindow::on_btn_CriticalDlg_clicked()
{
    m_err->setWindowTitle(tr("这里是出错信息"));
    m_err->showMessage(tr("这里是出错的信息"));
}

void MainWindow::on_btn_GuidDlg_clicked()
{
    QWizard wizard(this);
    wizard.setWindowTitle(tr("向导对话框"));
    wizard.addPage(page01());
    wizard.addPage(page02());
    wizard.addPage(page03());
    wizard.exec();
}

QWizardPage *MainWindow::page01()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle(tr("介绍"));
    return page;
}

QWizardPage *MainWindow::page02()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle(tr("用户选择信息"));
    return page;
}

QWizardPage *MainWindow::page03()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle(tr("结束"));
    return page;
}
