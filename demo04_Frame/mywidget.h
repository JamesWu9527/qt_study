#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class MyWidget; }
QT_END_NAMESPACE

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

private slots:
    void on_pushBtn1_toggled(bool checked);
    void lineEdit2_returnPressed();
    void spinBoxChangeValue(int value);

private:
    Ui::MyWidget *ui;
};
#endif // MYWIDGET_H
