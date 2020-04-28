#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class mywidget; }
QT_END_NAMESPACE

class mywidget : public QWidget
{
    Q_OBJECT

public:
    mywidget(QWidget *parent = nullptr);
    ~mywidget();

private:
    Ui::mywidget *ui;
};
#endif // MYWIDGET_H
