#ifndef MYSUBWIDGET_H
#define MYSUBWIDGET_H

#include <QWidget>
#include <QPushButton>
class MySubWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MySubWidget(QWidget *parent = nullptr);

signals:
    void ChangeSignal();
    void ChangeSignal(int a, QString str);

private:
    void ChangeSlots();

private:
    QPushButton *m_btn;
};

#endif // MYSUBWIDGET_H
