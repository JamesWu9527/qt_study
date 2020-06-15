#include "widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //初始化一些控件
    QPushButton *myBtn = new QPushButton;
    myBtn->setParent(this);
    myBtn->move(100,100);
    myBtn->setText(QString("我是一个按钮"));

    QPushButton *myBtn2 = new QPushButton("我来连接信号",this);
    resize(600,400);

    this->m_pTer = new Teacher(this);
    this->m_pStu = new Student(this);


    //将按钮 myBtn 和 槽函数 condition连接起来； 通过按钮的clicked事件 来进行连接
    connect(myBtn, &QPushButton::clicked, this, &Widget::Condition);

    //将teacher中的信号sayHello 和Student中的 RequestTeacher进行连接 如果这个信号和槽函数是唯一的 可以用下面的写法
    void(Teacher:: *TeacherSignal1)(void) = &Teacher::SayHello;
    void(Student:: *StudentSlots1)(void) = &Student::RequestTeacher;
    connect(m_pTer, TeacherSignal1, m_pStu, StudentSlots1);

    //现在是带参数的 写法如下
    void(Teacher:: *TeacherSignal2)(QString) = &Teacher::SayHello;
    void(Student:: *StudentSlots2)(QString) = &Student::RequestTeacher;
    connect(m_pTer, TeacherSignal2, m_pStu, StudentSlots2);

    //通过按钮2的clicked信号来连接TeacherSignal
    connect(myBtn2, &QPushButton::clicked, m_pTer, TeacherSignal1);   //信号连接信号的例子

    //使用lambda表达式 来点击按钮 关闭某个窗口
    QPushButton *myBtn3 = new QPushButton;
    myBtn3->setParent(this);
    myBtn3->move(300,300);
    myBtn3->setText(QString("使用lambda表达式的按钮"));

    connect(myBtn3, &QPushButton::clicked, this, [=](){this->close();});

    QPushButton *myBtn4 = new QPushButton;
    myBtn4->setParent(this);
    myBtn4->move(30,30);
    myBtn4->setText(QString("练习题"));

    m_bflag = false;
    m_pDlg = new TestDlg(this);
    //m_pDlg->resize(600,400);

    connect(myBtn4, &QPushButton::clicked, m_pDlg,[=](){
        if (!m_bflag)
        {
            myBtn4->setText("关闭");
           // m_pDlg->show();
        }
        else
        {
            myBtn4->setText("打开");
            //m_pDlg->CloseWindows();
        }

    });


}

Widget::~Widget()
{

}

void Widget::Condition()
{
    //这是显示的信号触发方式
    emit m_pTer->SayHello();
    emit m_pTer->SayHello("JamesWu9527");
    //disconnect(m_pTer, &Teacher::SayHello, m_pStu, &Student::RequestTeacher);
}

