#include "mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QDebug>
#include <QPushButton>
#include <QLabel>
#include <QStatusBar>
#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(600,400);

    //创建菜单栏 最多只有一个
    QMenuBar *bar = new QMenuBar();
    setMenuBar(bar);

    //创建菜单
    QMenu *fileMenu = bar->addMenu("文件");
    QMenu *editMenu = bar->addMenu("编辑");

    //创建菜单项目
    QAction *newaction = fileMenu->addAction("新建");
    //添加分割线
    fileMenu->addSeparator();
    QAction *openaction = fileMenu->addAction("打开");
    editMenu->addAction("测试1");
    editMenu->addSeparator();
    editMenu->addAction("测试2");

    //工具栏的创建
    QToolBar *toolBar = new QToolBar(this);
    this->addToolBar(Qt::LeftToolBarArea,toolBar);

    //只允许左右移动
    toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
    toolBar->setFloatable(false);       //设置是否浮动
    toolBar->setMovable(false);         //设置是否移动

    //在工具栏中设置内容
    toolBar->addAction(newaction);
    toolBar->addAction(openaction);

    //工具栏添加按钮
    QPushButton *btn = new QPushButton("测试按钮",this);
    toolBar->addWidget(btn);

    //状态栏 最多只有一个
    QStatusBar *stBar = new QStatusBar();
    //设置到窗口中
    this->setStatusBar(stBar);

    //放标签控件
    QLabel *label1 = new QLabel("提示信息1",this);
    stBar->addWidget(label1);

    QLabel *label2 = new QLabel("我在右边",this);
    stBar->addPermanentWidget(label2);

    //铆接部件  浮动窗口
    QDockWidget *dockwidget = new QDockWidget("浮动窗口",this);
    this->addDockWidget(Qt::BottomDockWidgetArea,dockwidget);
    dockwidget->setAllowedAreas(Qt::LeftDockWidgetArea);        //只允许停靠在左边

    //设置中心部件 只能一个
    QTextEdit *edit = new QTextEdit("编辑窗口",this);
    setCentralWidget(edit);


}

MainWindow::~MainWindow()
{
}

