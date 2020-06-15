#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "teacher.h"
#include "student.h"
#include "testdlg.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void Condition();       //通过这个方法来激活这个信号

private:
    Teacher *m_pTer;
    Student *m_pStu;
    TestDlg *m_pDlg;
    bool m_bflag;
};
#endif // WIDGET_H
